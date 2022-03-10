#include <iostream>
#include <vector>
#include <type_traits>
#include <limits>
#include <cstring>  // strcmp


namespace X13_7 {


// Stroustrup's first suggestion, the STL `sort()`, uses an algorithm called
//   Introsort, a hybrid of Quicksort, Insertion Sort, and Heapsort, see:
//   - https://www.geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-weapon/
//   - https://en.wikipedia.org/wiki/Introsort
//   - https://www.techiedelight.com/introsort-algorithm/
// For simplicity's sake, this implementation instead looks to qsort(),
//   specifically the Lomuto partition scheme, see:
//   - https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme
//
// algorithm quicksort(A, lo, hi) is
//   if lo < hi then
//       p := partition(A, lo, hi)
//       quicksort(A, lo, p - 1)
//       quicksort(A, p + 1, hi)
//
// algorithm partition(A, lo, hi) is
//   pivot := A[hi]
//   i := lo
//   for j := lo to hi do
//       if A[j] < pivot then
//           swap A[i] with A[j]
//           i := i + 1
//   swap A[i] with A[hi]
//   return i


static void SwapBufferContent(void *a, void *b, const std::size_t sz) {
    char *buf1 {static_cast<char *>(a)};  // for single-byte pointer arithmetic
    char *buf2 {static_cast<char *>(b)};
    for (std::size_t i {0}; i < sz; ++i) {
        char temp {buf1[i]};
        buf1[i] = buf2[i];
        buf2[i] = temp;
    }
}


static int LQSortPartition(
    const std::vector<void *> &vp_vec, const std::size_t sz,
    int (*compar)(const void *, const void *),
    const int lo_i, const int hi_i) {

    void *pivot {vp_vec[hi_i]};
    int i {lo_i};
    for (auto j {lo_i}; j < hi_i; ++j) {
        if (compar(vp_vec[j], pivot) < 0) {
            SwapBufferContent(vp_vec[i], vp_vec[j], sz);
            ++i;
        }
    }
    SwapBufferContent(vp_vec[i], vp_vec[hi_i], sz);
    return i;
}


static void LomutoQuickSort (
    const std::vector<void *> &vp_vec, const std::size_t sz,
    int (*compar)(const void *, const void *),
    const int lo_i, const int hi_i) {
    // Indicies must be a signed type, as a potential base case is when p = 0,
    //   and the next two calls are with a lo_i and hi_i of 0/-1, and 1/0,
    //   respectively, which causes the `if (lo_i < hi_i)` test to fail in both
    //   and end the recursion.
    // Using a unsigned index type would cause underflow, and thus invalid reads,
    //   on (p = 0) - 1. This could be alternatively remedied by testing `if (p)`
    //   as a condition for recursing.
    if (lo_i < hi_i) {
        const int p {LQSortPartition(vp_vec, sz, compar, lo_i, hi_i)};
            LomutoQuickSort(vp_vec, sz, compar, lo_i, p - 1);
            LomutoQuickSort(vp_vec, sz, compar, p + 1, hi_i);
    }
}


void qsort(void *base, const std::size_t n, const std::size_t sz,
           int (*compar)(const void *, const void *)) {
    if (base == nullptr || compar == nullptr)
        return;

    std::vector<void *> vp_vec;
    char *p {static_cast<char *>(base)};
    for (std::size_t i {0}; i < n; ++i)
        vp_vec.push_back(p + (i * sz));
    LomutoQuickSort(vp_vec, sz, compar, 0, n - 1);
}


template <typename T>
int VP_NumCmp(const void *a, const void *b) {
    static_assert(std::is_arithmetic<T>::value,
                  "VP_NumCmp must be used with an integral or "
                  "floating-point type.");
    T diff {*static_cast<const T *>(a) -
            *static_cast<const T *>(b)};
    if (diff > std::numeric_limits<int>::max())
        return std::numeric_limits<int>::max();
    if (diff < std::numeric_limits<int>::min())
        return std::numeric_limits<int>::min();
    if (std::is_floating_point<T>::value) {
        if (diff < 0 && diff > -1)
            return -1;
        if (diff > 0 && diff < 1)
            return 1;
    }
    return static_cast<int>(diff);
}


int VP_strcmp(const void *a, const void *b) {
    return std::strcmp(*static_cast<char * const *>(a),
                       *static_cast<char * const *>(b));
}


}  //namespace X13_7


int main() {
    constexpr int arr_sz {6};

    const char *str_arr[arr_sz] { "rety", "Radfk", "qwer", "asdf", "ptiyu", "jkhl" };
    int int_arr[arr_sz] { 345, 123, 34, 1, -567, 123 };

    for (auto i {0}; i < arr_sz; ++i) {
        std::cout << str_arr[i] << ' ';
    }
    std::cout << std::endl;
    X13_7::qsort(str_arr, arr_sz, sizeof(char *), X13_7::VP_strcmp);
    for (auto i {0}; i < arr_sz; ++i) {
        std::cout << str_arr[i] << ' ';
    }
    std::cout << std::endl;

    for (auto i {0}; i < arr_sz; ++i) {
        std::cout << int_arr[i] << ' ';
    }
    std::cout << std::endl;
    X13_7::qsort(int_arr, arr_sz, sizeof(int), X13_7::VP_NumCmp<int>);
    for (auto i {0}; i < arr_sz; ++i) {
        std::cout << int_arr[i] << ' ';
    }
    std::cout << std::endl;
}

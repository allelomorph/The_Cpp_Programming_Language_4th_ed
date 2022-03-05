#include <iostream>
#include <iomanip>    // setw
#include <vector>
#include <array>
#include <string>
#include <numeric>    // accumulate
#include <algorithm>  // for_each
#include <chrono>
#include <map>


namespace X12_3 {


// Originally thought to generalize for both container and element types, but
//   later settled on std::array for testing. Theoretically templates could be
//   generalized to at least work with std::vector and std::string as well,
//   given that they have both iterators and pointer access via `.data()`. An
//   example:
//
// template <typename ContainerType,
//           typename ElementType = typename ContainerType::value_type,
//           typename SizeType = typename ContainerType::size_type>
// ElementType Accum_1(ContainerType &cont) {
//     ElementType sum {};
//     SizeType sz { cont.size() };
//     for (SizeType i {0}; i < sz; ++i)
//         sum += cont[i];
//     return sum;
// }


template <typename ElementType, std::size_t Size>
ElementType Accum_0_Std_Accumulate(std::array<ElementType, Size> &arr) {
    return std::accumulate(arr.begin(), arr.end(), 0);
}


template <typename ElementType, std::size_t Size>
ElementType Accum_1_For_Indicies(std::array<ElementType, Size> &arr) {
    ElementType sum {};
    for (std::size_t i {0}; i < Size; ++i)
        sum += arr[i];
    return sum;
}


template <typename ElementType, std::size_t Size>
ElementType Accum_2_For_Pointers(std::array<ElementType, Size> &arr) {
    ElementType sum {};
    std::ptrdiff_t _Size { Size };
    auto first_p { arr.data() };
    for (auto p {first_p}; (p - first_p) < _Size; ++p)
        sum += *p;
    return sum;
}


template <typename ElementType, std::size_t Size>
ElementType Accum_3_For_Iterators(std::array<ElementType, Size> &arr) {
    ElementType sum {};
    for (auto itr { arr.begin() }; itr != arr.end(); ++itr)
        sum += *itr;
    return sum;
}


template <typename ElementType, std::size_t Size>
ElementType Accum_4_Range_For(std::array<ElementType, Size> &arr) {
    ElementType sum {};
    for (auto &x : arr)
        sum += x;
    return sum;
}


template <typename ElementType>
class Accum_5_FO {
public:
    void operator()(ElementType i) { sum += i; }
    ElementType sum {};
};


template <typename ElementType, std::size_t Size>
ElementType Accum_5_For_Each_FuncObj(std::array<ElementType, Size> &arr) {
    Accum_5_FO<ElementType> Sum_FO;
    return std::for_each(arr.begin(), arr.end(), Sum_FO).sum;
}


template <typename ElementType, std::size_t Size>
ElementType Accum_6_For_Each_Lambda(std::array<ElementType, Size> &arr) {
    ElementType sum {};
    std::for_each(arr.begin(), arr.end(),
                  [&sum](ElementType &e){ sum += e; });
    return sum;
}


template <typename ElementType, std::size_t Size>
void TestAccumulators(std::array<ElementType, Size> &arr,
                      unsigned int test_ct) {
    std::map<const std::string,
             ElementType (*)(std::array<ElementType, Size> &)> accums {
        { "X12_3::Accum_0_Std_Accumulate",   Accum_0_Std_Accumulate },
        { "X12_3::Accum_1_For_Indicies",     Accum_1_For_Indicies },
        { "X12_3::Accum_2_For_Pointers",     Accum_2_For_Pointers },
        { "X12_3::Accum_3_For_Iterators",    Accum_3_For_Iterators },
        { "X12_3::Accum_4_Range_For",        Accum_4_Range_For },
        { "X12_3::Accum_5_For_Each_FuncObj", Accum_5_For_Each_FuncObj },
        { "X12_3::Accum_6_For_Each_Lambda",  Accum_6_For_Each_Lambda }
    };

    for (auto &pair : accums) {
        std::vector<long> trials {};
        auto sum {pair.second(arr)};
        for (unsigned int i {0}; i < test_ct; ++i) {
            auto start {std::chrono::high_resolution_clock::now()};
            pair.second(arr);
            auto end {std::chrono::high_resolution_clock::now()};
            trials.push_back((end - start).count());
        }
        std::cout << std::setw(32) << pair.first <<
            " output: " << sum <<
            " calculated in an average of: " << std::setw(5) <<
            std::accumulate(trials.begin(), trials.end(), 0) / trials.size() <<
            " nanoseconds in " << test_ct << " trials" << std::endl;
    }
}


}  // namespace X12_3



int main() {
    constexpr unsigned int arr_sz  {100};
    constexpr unsigned int test_ct {50};

    std::array<int, arr_sz> int_arr;
    for (unsigned int i {0}; i < arr_sz; ++i)
        int_arr[i] = i;
    std::cout << "Testing with std::array<int, " << arr_sz << ">:" << std::endl;
    X12_3::TestAccumulators(int_arr, test_ct);

    std::cout << std::endl;
    std::array<double, arr_sz> dbl_arr;
    for (unsigned int i {0}; i < arr_sz; ++i)
        dbl_arr[i] = i;
    std::cout << "Testing with std::array<double, " << arr_sz << ">:" << std::endl;
    X12_3::TestAccumulators(dbl_arr, test_ct);
}

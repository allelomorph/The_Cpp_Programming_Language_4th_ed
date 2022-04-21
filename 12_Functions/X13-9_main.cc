#include <iostream>
#include <array>
#include <algorithm>


namespace X13_9 {


// Not many sources for the definition of "inverting" a 2D array were found,
//   but from those that were, it seems to be making every row a column, see:
//   - https://www.chegg.com/homework-help/questions-and-answers/write-method-inverts-2d-array-inverting-2d-array-means-row-2d-array-column-column-row-exam-q67877152
//   - https://cboard.cprogramming.com/cplusplus-programming/128538-inverting-2d-array.html
// Going by this definition, the array's 2 dimsensions would have to be equal.
//   Also, not to be confused with an inverse matrix:
//   - https://byjus.com/maths/inverse-matrix/

template <typename T, std::size_t W, std::size_t H>
void Invert2DArray(std::array<std::array<T, W>, H> &array) {
    static_assert(W == H, "Can only invert arrays with equal width and height");
    for (std::size_t y {0}, x_start {1}; y < H; ++y, ++x_start) {
        for (std::size_t x {x_start}; x < W; ++x) {
            std::swap(array[y][x], array[x][y]);
        }
    }
}


template <typename T, std::size_t W, std::size_t H>
void Print2DArray(const std::array<std::array<T, W>, H> &array) {
    for (auto &row : array) {
        for (auto &elem : row) {
            std::cout << '[' << elem << "] ";
        }
        std::cout << std::endl;
    }
}


}  // namespace X13_9


int main() {
    // std::array needs extra set of braces in initializers, see:
    //   - https://stackoverflow.com/q/12844475/
    std::array<std::array<int, 3>, 3> i_arr {{
            {{0, 1, 2}},
            {{3, 4, 5}},
            {{6, 7, 8}}
        }};
    std::array<std::array<char, 3>, 3> c_arr {{
            {{'A', 'B', 'C'}},
            {{'D', 'E', 'F'}},
            {{'G', 'H', 'I'}}
        }};

    X13_9::Print2DArray(i_arr);
    std::cout << std::endl;
    X13_9::Invert2DArray(i_arr);
    X13_9::Print2DArray(i_arr);
    std::cout << std::endl;

    X13_9::Print2DArray(c_arr);
    std::cout << std::endl;
    X13_9::Invert2DArray(c_arr);
    X13_9::Print2DArray(c_arr);
}

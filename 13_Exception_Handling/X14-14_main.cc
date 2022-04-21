#include "X14-14_arithmetic_ops.hh"
#include <iostream>
#include <vector>
#include <array>


int main() {
    std::vector<std::array<int, 2>> int_tests {
        {0, 0}, {0, 1}, {1, 0}, {1, 1},
        {-1, 1}, {1, -1}, {-1, -1},
        {std::numeric_limits<int>::max(), 0}, {0, std::numeric_limits<int>::max()},
        {std::numeric_limits<int>::min(), 0}, {0, std::numeric_limits<int>::min()},
        {std::numeric_limits<int>::max(), 1}, {1, std::numeric_limits<int>::max()},
        {std::numeric_limits<int>::max(), -1}, {-1, std::numeric_limits<int>::max()},
        {std::numeric_limits<int>::min(), 1}, {1, std::numeric_limits<int>::min()},
        {std::numeric_limits<int>::min(), -1}, {-1, std::numeric_limits<int>::min()}
    };
    for (auto &p : int_tests) {
        try {
            std::cout << "plus(" << p[0] << ", " << p[1] << "): " <<
                X14_14::plus(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (auto &p : int_tests) {
        try {
            std::cout << "minus(" << p[0] << ", " << p[1] << "): " <<
                X14_14::minus(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (auto &p : int_tests) {
        try {
            std::cout << "multiply(" << p[0] << ", " << p[1] << "): " <<
                X14_14::multiply(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (std::size_t i {1}; i != int_tests.size();) {
        try {
            std::cout << "divide(" << int_tests[i][0] << ", " << int_tests[i][1] << "): " <<
                X14_14::divide(int_tests[i][0], int_tests[i][1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        if (i == 1 || i == 6 || i == 8)
            i += 2;
        else
            ++i;
    }

    std::vector<std::array<float, 2>> flt_tests {
        {0, 0}, {0, 1}, {1, 0}, {1, 1},
        {-1, 1}, {1, -1}, {-1, -1},
        {1, .5}, {.5, 1}, {.5, .5},
        {-1, .5}, {-.5, 1}, {-.5, .5},
        {1, -.5}, {.5, -1}, {.5, -.5},
        {-1, -.5}, {-.5, -1}, {-.5, -.5},
        {std::numeric_limits<float>::max(), 0}, {0, std::numeric_limits<float>::max()},
        {std::numeric_limits<float>::min(), 0}, {0, std::numeric_limits<float>::min()},
        {std::numeric_limits<float>::max(), 1}, {1, std::numeric_limits<float>::max()},
        {std::numeric_limits<float>::min(), -1}, {-1, std::numeric_limits<float>::min()},
        {std::numeric_limits<float>::max(), std::numeric_limits<float>::max()},
        {-std::numeric_limits<float>::max(), std::numeric_limits<float>::max()},
        {std::numeric_limits<float>::max(), -std::numeric_limits<float>::max()},
        {-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max()},
        {std::numeric_limits<float>::min(), std::numeric_limits<float>::min()},
        {-std::numeric_limits<float>::min(), std::numeric_limits<float>::min()},
        {std::numeric_limits<float>::min(), -std::numeric_limits<float>::min()},
        {-std::numeric_limits<float>::min(), -std::numeric_limits<float>::min()}
    };
    for (auto &p : flt_tests) {
        try {
            std::cout << "plus(" << p[0] << ", " << p[1] << "): " <<
                X14_14::plus(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (auto &p : flt_tests) {
        try {
            std::cout << "minus(" << p[0] << ", " << p[1] << "): " <<
                X14_14::minus(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (auto &p : flt_tests) {
        try {
            std::cout << "multiply(" << p[0] << ", " << p[1] << "): " <<
                X14_14::multiply(p[0], p[1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    for (std::size_t i {1}; i != flt_tests.size();) {
        try {
            std::cout << "divide(" << flt_tests[i][0] << ", " << flt_tests[i][1] << "): " <<
                X14_14::divide(flt_tests[i][0], flt_tests[i][1]) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        if (i == 1 || i == 18 || i == 20)
            i += 2;
        else
            ++i;
    }
}

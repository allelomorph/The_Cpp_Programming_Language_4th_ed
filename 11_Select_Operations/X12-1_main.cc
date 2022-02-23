#include <iostream>
#include <iomanip>   // setw
#include <vector>
#include "UniformRandIntGen.hh"


int main() {
    constexpr std::size_t arr_sz {40};
    UniformRandIntGen<int> rnd(0, 10);
    int arr[arr_sz];
    std::vector<int> vect;

    for (std::size_t i {0}; i < arr_sz; ++i)
        arr[i] = rnd();

    for (int *p {arr}; (p - arr) < static_cast<long int>(arr_sz); ++p) {
        if (*p)
            vect.push_back(*p);
    }

    std::cout << "arr[n]:" << std::endl;
    for (std::size_t i {0}; i < arr_sz; ++i) {
        std::cout << '[' << std::setw(2) << i << "]: " <<
            std::setw(2) << arr[i] << ' ';
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "vect[n]:" << std::endl;
    for (std::size_t i {0}; i < vect.size(); ++i) {
        std::cout << '[' << std::setw(2) << i << "]: " <<
            std::setw(2) << vect[i] << ' ';
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

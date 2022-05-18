#include "X14-5_Vector.hh"
#include <iostream>


int main() {
    X14_5::Vector<int> v1 (1, 1);               // explcit constructor
    std::cout << "v1.size(): " <<               // size() "1"
        v1.size() << std::endl;
    std::cout << "v1.capacity(): " <<           // capacity() "1" (extra space 0 by default)
        v1.capacity() << std::endl;
    std::cout << "v1.at(0): " << v1.at(0) << ' ';  // at()
    try {
        std::cout << "v1.at(1): " << v1.at(1);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    X14_5::Vector<int> v2 {v1};                 // copy constructor
    v2 = v1;                                    // copy assignment

    X14_5::Vector<int> v3 {X14_5::Vector<int> {3, 1}};  // move constructor
    v3 = X14_5::Vector<int> {3, 1};             // move assignment

    v1.reserve(5);                              // reserve()
    std::cout << "after v1.reserve(5): ";
    std::cout << "v1.size(): " <<               // "1"
        v1.size();
    std::cout << " v1.capacity(): " <<          // "1" (extra space 0 by default)
        v1.capacity() << std::endl;

    v1.resize(10);                              // resize()
    std::cout << "after v1.resize(10): ";
    std::cout << "v1.size(): " <<               // "1"
        v1.size();
    std::cout << " v1.capacity(): " <<          // "1" (extra space 0 by default)
        v1.capacity() << std::endl;

    v2.push_back(1);                            // push_back()

    // Can't use range-for loop or iterators until implemented for X14_5::Vector
    for (std::size_t i {}; i < v1.size(); ++i)
        std::cout << v1[i] << ' ';
    std::cout << std::endl;
    for (std::size_t i {}; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';
    std::cout << std::endl;
    for (std::size_t i {}; i < v3.size(); ++i)
        std::cout << v3[i] << ' ';
    std::cout << std::endl;

    try {
        std::cout <<
            "v1.reserve((std::size_t {std::numeric_limits<ptrdiff_t>::max)) "
            "/ sizeof(int)) + 1): ";
        v1.reserve((std::size_t (std::numeric_limits<ptrdiff_t>::max) /
                    sizeof(int)) + 1);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

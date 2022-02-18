#include <iostream>
#include <bitset>


int main() {
    std::bitset<8> bitset;

    std::cout <<
        "AND:" << std::endl <<
        "0 & 0: " << (0 & 0) << std::endl <<
        "0 & 1: " << (0 & 1) << std::endl <<
        "1 & 0: " << (1 & 0) << std::endl <<
        "1 & 1: " << (1 & 1) << std::endl << std::endl;
    std::cout <<
        "OR:" << std::endl <<
        "0 | 0: " << (0 | 0) << std::endl <<
        "0 | 1: " << (0 | 1) << std::endl <<
        "1 | 0: " << (1 | 0) << std::endl <<
        "1 | 1: " << (1 | 1) << std::endl << std::endl;
    std::cout <<
        "XOR:" << std::endl <<
        "0 ^ 0: " << (0 ^ 0) << std::endl <<
        "0 ^ 1: " << (0 ^ 1) << std::endl <<
        "1 ^ 0: " << (1 ^ 0) << std::endl <<
        "1 ^ 1: " << (1 ^ 1) << std::endl << std::endl;

    std::cout << "Complement:" << std::endl;
    bitset = 0;
    std::cout << "~0 ~(" << bitset << "): " <<
        ~0 << " (" << ~bitset << ')' << std::endl;
    bitset = 1;
    std::cout << "~1 ~(" << bitset << "): " <<
        ~1 << " (" << ~bitset << ')' << std::endl << std::endl;

    std::cout << "Right shift:" << std::endl;
    bitset = 0;
    std::cout << "0 >> 0 (" << bitset << " >> 0): " <<
        (0 >> 0) << " (" << (bitset >> 0) << ')' << std::endl;
    std::cout << "0 >> 1 (" << bitset << " >> 1): " <<
        (0 >> 1) << " (" << (bitset >> 1) << ')' << std::endl;
    bitset = 1;
    std::cout << "1 >> 0 (" << bitset << " >> 0): " <<
        (1 >> 0) << " (" << (bitset >> 0) << ')' << std::endl;
    std::cout << "1 >> 1 (" << bitset << " >> 1): " <<
        (1 >> 1) << " (" << (bitset >> 1) << ')' << std::endl << std::endl;

    std::cout << "Left shift:" << std::endl;
    bitset = 0;
    std::cout << "0 << 0 (" << bitset << " << 0): " <<
        (0 << 0) << " (" << (bitset << 0) << ')' << std::endl;
    std::cout << "0 << 1 (" << bitset << " << 1): " <<
        (0 << 1) << " (" << (bitset << 1) << ')' << std::endl;
    bitset = 1;
    std::cout << "1 << 0 (" << bitset << " << 0): " <<
        (1 << 0) << " (" << (bitset << 0) << ')' << std::endl;
    std::cout << "1 << 1 (" << bitset << " << 1): " <<
        (1 << 1) << " (" << (bitset << 1) << ')' << std::endl;
}

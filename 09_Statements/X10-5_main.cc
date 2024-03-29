#include <iostream>
#include <limits>
#include <cstring>   // memset


namespace X10_5 {


void _atoiRecursion(int i, char *b, int pow_10, bool negative) {
    if (pow_10 <= 0)
        return;
    int digit_base {i / pow_10};
    // must reverse sign digit by digit to include case of INT_MIN
    *b++ = negative ? (digit_base * -1) + '0' : digit_base + '0';
    return _atoiRecursion(i % pow_10, b, pow_10 / 10, negative);
}


void itoa(int i, char *b) {
    if (b == nullptr)
        throw std::invalid_argument("X10_5::itoa: null buffer");

    bool neg { (i < 0) };
    if (neg)
        *b++ = '-';

    int pow_10 {1};
    for (int j {i / 10}; j; j /= 10)
        pow_10 *= 10;

    return _atoiRecursion(i, b, pow_10, neg);
}


void itoaTestPrint(int i, char *buf, size_t buf_sz) {
    X10_5::itoa(i, buf);
    std::cout << "X10_5::itoa(" << i << ", buf): \"" << buf << '"' << std::endl;
    std::memset(buf, 0, buf_sz);
}


}  // namespace X10_5


int main() {
    constexpr std::size_t buf_sz {21};
    char buf[buf_sz] {0};   // max chars == 20 (LONG_MAX, -9223372036854775808)

    try {
        std::cout << "X10_5::itoa(n, nullptr): ";
        X10_5::itoa(10, nullptr);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    X10_5::itoaTestPrint(0, buf, buf_sz);
    X10_5::itoaTestPrint(-0, buf, buf_sz);
    X10_5::itoaTestPrint(123, buf, buf_sz);
    X10_5::itoaTestPrint(-123, buf, buf_sz);
    X10_5::itoaTestPrint(std::numeric_limits<int>::min(), buf, buf_sz);
    X10_5::itoaTestPrint(std::numeric_limits<int>::max(), buf, buf_sz);

    std::cout << "std::numeric_limits<long int>::min(): " << std::numeric_limits<long int>::min() << std::endl;
    std::cout << "std::numeric_limits<long int>::max(): " << std::numeric_limits<long int>::max() << std::endl;
}

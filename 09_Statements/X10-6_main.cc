#include <iostream>
#include <limits>
#include <cstring>   // memset


namespace X10_6 {


void _atoiRecursion(int i, char *b, int pow_10, bool negative) {
    if (pow_10 <= 0)
        return;
    int digit_base {i / pow_10};
    // must reverse sign digit by digit to include case of INT_MIN
    *b++ = negative ? (digit_base * -1) + '0' : digit_base + '0';
    return _atoiRecursion(i % pow_10, b, pow_10 / 10, negative);
}


void itoa(int i, char *b, std::size_t buf_sz) {
    if (b == nullptr)
        throw std::invalid_argument("X10_6::itoa: null buffer");
    if (!buf_sz)
        return;

    std::size_t rep_len {1};  // representation length (minimum 1 digit)
    bool neg { (i < 0) };
    if (neg)
        ++rep_len;

    int pow_10 {1};
    for (int j {i / 10}; j; j /= 10) {
        ++rep_len;
        pow_10 *= 10;
    }
    if (buf_sz < rep_len)
        throw std::out_of_range("X10_6::itoa: buffer too small for numeral string");

    if (neg)
        *b++ = '-';
    return _atoiRecursion(i, b, pow_10, neg);
}


void itoaTestPrint(int i, char *buf, std::size_t buf_sz) {
    X10_6::itoa(i, buf, buf_sz);
    std::cout << "X10_6::itoa(" << i << ", buf): \"" << buf << '"' << std::endl;
    std::memset(buf, 0, buf_sz);
}


}  // namespace X10_6


int main() {
    constexpr std::size_t buf_sz {21};
    char buf[buf_sz] {0};   // max chars == 20 (LONG_MAX, -9223372036854775808)

    try {
        std::cout << "X10_6::itoa(n, nullptr): ";
        X10_6::itoa(10, nullptr, buf_sz);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    X10_6::itoaTestPrint(0, buf, buf_sz);
    X10_6::itoaTestPrint(-0, buf, buf_sz);
    X10_6::itoaTestPrint(123, buf, buf_sz);
    X10_6::itoaTestPrint(-123, buf, buf_sz);
    X10_6::itoaTestPrint(std::numeric_limits<int>::min(), buf, buf_sz);
    X10_6::itoaTestPrint(std::numeric_limits<int>::max(), buf, buf_sz);
}

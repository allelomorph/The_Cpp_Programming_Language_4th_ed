#include <iostream>
#include <cctype>     // isspace isdigit isxdigit


namespace X10_3 {

int atoi(const char *s) {
    if (s == nullptr)
        throw std::invalid_argument("X10_3::atoi: null string");

    while (std::isspace(*s))
        ++s;

    int negative {1};
    if (*s == '-') {
        negative = -1;
        ++s;
    }
    // std::atoi returns 0 for bad numeral strings, so not throwing exceptions
    //  for "" or naked '-', "0x", or "0X"
    bool cap_hex {false};
    int base {10};
    if (*s == '0') {
        ++s;
        if (*s == 'x' || (cap_hex = (*s == 'X'))) {
            ++s;
            base = 16;
        } else {
            base = 8;
        }
    }
    // advance to lowest place digit in representation
    const char *rep_start {s};
    if (base == 16)
        while (std::isxdigit(*s)) ++s;
    else
        while (std::isdigit(*s)) ++s;
    --s;
    char rep_ch[17] { "0123456789abcdef" };
    if (cap_hex) {
        for (auto i = 10; rep_ch[i]; ++i)
            rep_ch[i] -= ' ';
    }
    int res {0};
    for (int pow {1}; s - rep_start >= 0; --s, pow *= base) {
        int i {0};
        for (; rep_ch[i]; ++i) {
            if (*s == rep_ch[i]) {
                res += i * pow;
                break;
            }
        }
        if (i == 16)
            throw std::invalid_argument("X10_3::atoi: mixed hex case");
    }
    return negative * res;
}

}  // namespace X10_3


int main() {
    try {
        std::cout << "atoi(nullptr): " << X10_3::atoi(nullptr) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "atoi(\"0xdF\"): " << X10_3::atoi("0xdF") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "atoi(\"\"): " << X10_3::atoi("") << std::endl;
    std::cout << "atoi(\"z\"): " << X10_3::atoi("z") << std::endl;
    std::cout << "atoi(\"-z\"): " << X10_3::atoi("-z") << std::endl;
    std::cout << "atoi(\"0z\"): " << X10_3::atoi("0z") << std::endl;
    std::cout << "atoi(\"0xz\"): " << X10_3::atoi("0xz") << std::endl;
    std::cout << "atoi(\"0Xz\"): " << X10_3::atoi("0Xz") << std::endl;

    std::cout << "\nReference std::dec << 0: " << 0 << std::endl;
    std::cout << X10_3::atoi("0") << std::endl;
    std::cout << X10_3::atoi("-0") << std::endl;
    std::cout << X10_3::atoi("    0") << std::endl;
    std::cout << X10_3::atoi("   -0") << std::endl;

    std::cout << "\nReference std::dec << 0x0: " << 0x0 << std::endl;
    std::cout << X10_3::atoi("0x0") << std::endl;
    std::cout << X10_3::atoi("-0x0") << std::endl;
    std::cout << X10_3::atoi("    0x0") << std::endl;
    std::cout << X10_3::atoi("   -0x0") << std::endl;

    std::cout << "\nReference std::dec << 123: " << 123 << std::endl;
    std::cout << X10_3::atoi("123") << std::endl;
    std::cout << X10_3::atoi("-123") << std::endl;
    std::cout << X10_3::atoi("    123") << std::endl;
    std::cout << X10_3::atoi("   -123") << std::endl;

    std::cout << "\nReference std::dec << 067: " << 067 << std::endl;
    std::cout << X10_3::atoi("067") << std::endl;
    std::cout << X10_3::atoi("-067") << std::endl;
    std::cout << X10_3::atoi("    067") << std::endl;
    std::cout << X10_3::atoi("   -067") << std::endl;

    std::cout << "\nReference std::dec << 0xdf: " << 0xdf << std::endl;
    std::cout << X10_3::atoi("0xdf") << std::endl;
    std::cout << X10_3::atoi("-0xdf") << std::endl;
    std::cout << X10_3::atoi("    0xdf") << std::endl;
    std::cout << X10_3::atoi("   -0xdf") << std::endl;

    std::cout << "\nReference std::dec << 0XDF: " << 0XDF << std::endl;
    std::cout << X10_3::atoi("0XDF") << std::endl;
    std::cout << X10_3::atoi("-0XDF") << std::endl;
    std::cout << X10_3::atoi("    0XDF") << std::endl;
    std::cout << X10_3::atoi("   -0XDF") << std::endl;
}

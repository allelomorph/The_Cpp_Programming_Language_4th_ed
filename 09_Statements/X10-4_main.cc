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

    // count digits in representation
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
        for (int i {0}; rep_ch[i]; ++i) {
            if (*s == rep_ch[i]) {
                res += i * pow;
                break;
            }
        }
    }

    return negative * res;
}

}  // namespace X10_3


int main() {
    std::cout << "\nReference std::dec << 123: " << 123 << std::endl;
    std::cout << X10_3::atoi("123") << std::endl;
    std::cout << X10_3::atoi("-123") << std::endl;
    std::cout << X10_3::atoi("    123") << std::endl;
    std::cout << X10_3::atoi("   -123") << std::endl;
//    std::cout << X10_3::atoi("   - 123") << std::endl;

    std::cout << "\nReference std::dec << 067: " << 067 << std::endl;
    std::cout << X10_3::atoi("067") << std::endl;
    std::cout << X10_3::atoi("-067") << std::endl;
    std::cout << X10_3::atoi("    067") << std::endl;
    std::cout << X10_3::atoi("   -067") << std::endl;
//    std::cout << X10_3::atoi("   - 067") << std::endl;

    std::cout << "\nReference std::dec << 0xdf: " << 0xdf << std::endl;
    std::cout << X10_3::atoi("0xdf") << std::endl;
    std::cout << X10_3::atoi("-0xdf") << std::endl;
    std::cout << X10_3::atoi("    0xdf") << std::endl;
    std::cout << X10_3::atoi("   -0xdf") << std::endl;
//    std::cout << X10_3::atoi("   - 0xdf") << std::endl;

    std::cout << "\nReference std::dec << 0XDF: " << 0XDF << std::endl;
    std::cout << X10_3::atoi("0XDF") << std::endl;
    std::cout << X10_3::atoi("-0XDF") << std::endl;
    std::cout << X10_3::atoi("    0XDF") << std::endl;
    std::cout << X10_3::atoi("   -0XDF") << std::endl;
//    std::cout << X10_3::atoi("   - 0XDF") << std::endl;
}

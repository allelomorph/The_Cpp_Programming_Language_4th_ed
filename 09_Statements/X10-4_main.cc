#include <iostream>
#include <cctype>     // isspace isdigit isxdigit
#include <cstdlib>    // atoi


// Not sure what Stroustrup is expecting when asking to "handle the C++ character
//   constant notation." Templatize the function to take char/char16_t/char32_t/
//   wchar_t parameters? Pass those values as a const char *? As a result, that
//   feature is currently unimplemented.


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
    //   for "", non-hexadecimal chars, and naked '-'/"0x"/"0X"
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
    char rep_ch[17] {"0123456789abcdef"};
    if (cap_hex) {
        for (auto i = 10; rep_ch[i]; ++i)
            rep_ch[i] -= ' ';
    }
    int res {0};
    for (int i, pow {1}; s - rep_start >= 0; --s, pow *= base) {
        for (i = 0; rep_ch[i]; ++i) {
            if (*s == rep_ch[i]) {
                res += i * pow;
                break;
            }
        }
        if (i == 16)
            throw std::invalid_argument("X10_3::atoi: mixed hexidecimal case");
    }
    return negative * res;
}


void atoiTestPrint(const char *s) {
    std::cout <<
        "std::atoi(\"" << s << "\"): " << std::atoi(s) <<
        "       X10_3::atoi(\"" << s << "\"): " << X10_3::atoi(s) <<
        std::endl;
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

    std::cout << std::endl;
    X10_3::atoiTestPrint("");
    X10_3::atoiTestPrint("z");
    X10_3::atoiTestPrint("-z");
    X10_3::atoiTestPrint("0z");
    X10_3::atoiTestPrint("0xz");
    X10_3::atoiTestPrint("0Xz");

    std::cout << "\nstd::cout << [std::dec <<] 0: " << 0 << std::endl;
    X10_3::atoiTestPrint("0");
    X10_3::atoiTestPrint("-0");
    X10_3::atoiTestPrint("    0");
    X10_3::atoiTestPrint("   -0");

    std::cout << "\nstd::cout << [std::dec <<] 0x0: " << 0x0 << std::endl;
    X10_3::atoiTestPrint("0x0");
    X10_3::atoiTestPrint("-0x0");
    X10_3::atoiTestPrint("    0x0");
    X10_3::atoiTestPrint("   -0x0");

    std::cout << "\nstd::cout << [std::dec <<] 123: " << 123 << std::endl;
    X10_3::atoiTestPrint("123");
    X10_3::atoiTestPrint("-123");
    X10_3::atoiTestPrint("    123");
    X10_3::atoiTestPrint("   -123");

    std::cout << "\nstd::cout << [std::dec <<] 067: " << 067 << std::endl;
    X10_3::atoiTestPrint("067");
    X10_3::atoiTestPrint("-067");
    X10_3::atoiTestPrint("    067");
    X10_3::atoiTestPrint("   -067");

    std::cout << "\nstd::cout << [std::dec <<] 0xdf: " << 0xdf << std::endl;
    X10_3::atoiTestPrint("0xdf");
    X10_3::atoiTestPrint("-0xdf");
    X10_3::atoiTestPrint("    0xdf");
    X10_3::atoiTestPrint("   -0xdf");

    std::cout << "\nstd::cout << [std::dec <<] 0XDF: " << 0XDF << std::endl;
    X10_3::atoiTestPrint("0XDF");
    X10_3::atoiTestPrint("-0XDF");
    X10_3::atoiTestPrint("    0XDF");
    X10_3::atoiTestPrint("   -0XDF");
}

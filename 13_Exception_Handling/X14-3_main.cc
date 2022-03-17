#include "X14-2_Int.hh"
// #include <string>
#include <limits>


int main() {
    using Int = X14_2::Int;

    // default constructor test
    Int I_1;
    std::cout << "I_1: " << I_1 << std::endl;
    // Same type rvalue constructor test
    Int I_2 {Int{2}};
    std::cout << "I_2: " << I_2 << std::endl;
    // Same type lvalue constructor test
    Int I_3 {I_2};
    std::cout << "I_3: " << I_3 << std::endl;
    // Same type rvalue assignment test
    Int I_4;
    I_4 = Int{4};
    std::cout << "I_4: " << I_4 << std::endl;
    // Same type lvalue asssignment test
    Int I_5;
    I_5 = I_4;
    std::cout << "I_5: " << I_5 << std::endl;

    // compatible integral lvalue constructor test 1
    int i {6};
    Int I_6 {i};
    std::cout << "I_6: " << I_6 << std::endl;
    // compatible integral lvalue constructor test 2
    char c {7};
    Int I_7 {c};
    std::cout << "I_7: " << I_7 << std::endl;
    // compatible floating point lvalue constructor test 1
    float f {8.0};
    Int I_8 {f};
    std::cout << "I_8: " << I_8 << std::endl;
    // compatible floating point lvalue constructor test 2
    double d {9.0};
    Int I_9 {d};
    std::cout << "I_9: " << I_9 << std::endl;

    // compatible integral lvalue assignment test 1
    int _i {10};
    Int I_10;
    I_10 = _i;
    std::cout << "I_10: " << I_10 << std::endl;
    // compatible integral lvalue assignment test 2
    int _c {11};
    Int I_11;
    I_11 = _c;
    std::cout << "I_11: " << I_11 << std::endl;
    // compatible floating point lvalue assignment test 1
    float _f {12.0};
    Int I_12;
    I_12 = _f;
    std::cout << "I_12: " << I_12 << std::endl;
    // compatible floating point lvalue assignment test 2
    double _d {13.0};
    Int I_13;
    I_13 = _d;
    std::cout << "I_13: " << I_13 << std::endl;

    // compatible integral rvalue constructor test 1
    Int I_14 {int{14}};
    std::cout << "I_14: " << I_14 << std::endl;
    // compatible integral rvalue constructor test 2
    Int I_15 {char{15}};
    std::cout << "I_15: " << I_15 << std::endl;
    // compatible floating point rvalue constructor test 1
    Int I_16 {float{16.0}};
    std::cout << "I_16: " << I_16 << std::endl;
    // compatible floating point rvalue constructor test 2
    Int I_17 {double{17.0}};
    std::cout << "I_17: " << I_17 << std::endl;

    // compatible integral rvalue assignment test 1
    Int I_18;
    I_18 = int{18};
    std::cout << "I_18: " << I_18 << std::endl;
    // compatible integral rvalue assignment test 2
    Int I_19;
    I_19 = char{19};
    std::cout << "I_19: " << I_19 << std::endl;
    // compatible floating point rvalue assignment test 1
    Int I_20;
    I_20 = float{20.0};
    std::cout << "I_20: " << I_20 << std::endl;
    // compatible floating point rvalue assignment test 2
    Int I_21;
    I_21 = double{21.0};
    std::cout << "I_21: " << I_21 << std::endl;

    long over_max {long{std::numeric_limits<int>::max()} + 1};
    // out_of_range lvalue test
    try {
        Int I_22 {over_max};
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // out_of_range rvalue test 1
    try {
        Int I_23 {long{std::numeric_limits<int>::min()} - 1};
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // out_of_range rvalue test 2
    try {
        Int I_24 {float(over_max * 2)};
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // invalid_argument may be redundant at run time, as non-arithmetic types
    //   cause errors at compile time
    // try {
    //     Int I_25 {std::string{}};
    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // The same is true of the standard int
    // int __i {std::string{}};
}

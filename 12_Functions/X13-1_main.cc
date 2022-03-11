// Printing function names from inside function, see:
//   - https://stackoverflow.com/a/17528983
// Related discussion of getting function name from function pointer, see:
//   - https://stackoverflow.com/q/351134

#ifndef __GNUG__
#error "Use of __func__ to get function name requires compilation with gcc/g++."
#endif


#include <iostream>


namespace X13_1 {

// Declarations of:
// - function taking arguments of type:
//   - pointer to character
//   - reference to integer
// returning no value
void F1(char *char_p, int &int_ref);


// - pointer to such a function:
void (*F1_p)(char *, int &);
// *_simple function declarations simplified with using declaration
using F1_pt = void (*)(char *, int &);


// function taking such a pointer as an argument:
void F2_verbose(void (*F1_p)(char *, int &));
void F2_simple(F1_pt);


// - function returning such a pointer, got raw syntax from:
//   - https://stackoverflow.com/questions/997821
//   pattern (rfp = returned function pointer, cf = current function):
//     [rfp return type] ( *[cf name] ( [cf params] ) ) ( [rfp params] )
void (*F3_verbose())(char *, int &);
F1_pt F3_simple();


// Definition of a function that takes such a pointer as an argument and
//   returns its argument as the return value:
void (*F4_verbose(void (*F1_p)(char *, int &)))(char *, int &) {
    std::cout << __func__ << std::endl;
    return F1_p;
}
F1_pt F4_simple(F1_pt F1_p) {
    std::cout << __func__ << std::endl;
    return F1_p;
}


// Dummy definitions for declared funcs to allow compilation:
void F1(char *char_p, int &int_ref) {
    std::cout << __func__ << std::endl;
    (void)char_p;
    (void)int_ref;
}


void F2_verbose(void (*F1_p)(char *, int &)) {
    std::cout << __func__ << std::endl;
    (void)F1_p;
}
void F2_simple(F1_pt F1_p) {
    std::cout << __func__ << std::endl;
    (void)F1_p;
}


void (*F3_verbose())(char *, int &) {
    std::cout << __func__ << std::endl;
    F1_pt f1_p {F1};
    return f1_p;
}
F1_pt F3_simple() {
    std::cout << __func__ << std::endl;
    F1_pt f1_p {F1};
    return f1_p;
}


}  // namespace X13_1


int main() {
    char c {};
    int i {};

    X13_1::F1(&c, i);

    X13_1::F1_pt f1_p1 {X13_1::F1};
    f1_p1(&c, i);

    X13_1::F2_verbose(f1_p1);
    X13_1::F2_simple(f1_p1);

    X13_1::F1_pt f1_p2 {X13_1::F3_verbose()};
    f1_p2(&c, i);
    X13_1::F1_pt f1_p3 {X13_1::F3_simple()};
    f1_p3(&c, i);

    X13_1::F1_pt f1_p4 {X13_1::F4_verbose(f1_p2)};
    f1_p4(&c, i);
    X13_1::F1_pt f1_p5 {X13_1::F4_simple(f1_p3)};
    f1_p5(&c, i);
}

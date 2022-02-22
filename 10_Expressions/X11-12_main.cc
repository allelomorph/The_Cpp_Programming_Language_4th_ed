#include "X11-12_Calculator.hh"
#include <iostream>
#include <sstream>


int main(){
    int total_errors {0};
    X11_12::Calculator calc;
    std::istringstream iss {"a = 3 / 2; b = (a * 4.1) + 1; b - 1"};

    calc.calculate();  // defaults to cin
    total_errors += calc.errors();

    calc.set_input(iss);   // std::istream &
    calc.calculate();
    total_errors += calc.errors();

    calc.set_input(new std::istringstream {
            "a = 3 / 2; b = (a * 4.1) + 1; b - 1"});  // std::istream *
    calc.calculate();
    total_errors += calc.errors();

#ifdef DEBUG
    calc.PrintNameTable();
#endif
    return total_errors;
}

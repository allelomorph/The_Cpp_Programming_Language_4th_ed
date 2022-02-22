#ifndef X11_12_CALCULATOR_HH
#define X11_12_CALCULATOR_HH


#include <map>
#include <string>
#include <iostream>


// Parsing Grammar
//
// program:
//     end
//     expr_list end
//
// expr_list:
//     expression print
//     expression print expr_list
//
// expression:
//     expression + term
//     expression - term
//     term
//
// term:
//     term / primary
//     term * primary
//     primary
//
// primary:
//     number   // floating point literal
//     name     // identifier
//     name = expression
//     - primary
//     ( expression )


namespace X11_12 {


enum class Kind : char {
    name, number, end,
    plus = '+', minus = '-', mul = '*', div = '/',
    print = ';', assign = '=', lp = '(', rp = ')'
};


struct Token {
    Kind        kind;
    std::string string_value;
    double      number_value;
};


// Reading ahead to 11.2.1, Stroustrup explains how the use of delete here in
//   close() is one simple way his TokenStream is a version of the STL vector
//   or string, in that is manages the cleanup of any objects created with new
//   that are passed during initialization, for example:
//      TokenStream ts{new std::istringstream{std::string s}};
class TokenStream {
public:
    TokenStream(std::istream &s) : ip{&s}, owns{false} {}
    TokenStream(std::istream *p) : ip{p}, owns{true} {}

    ~TokenStream() { close(); }

    Token get();                           // read and return next token
    const Token &current() { return ct; }  // most recently read token
    unsigned int line_n() { return parsed_line_ct; }

    void set_input(std::istream &s) {
        close();
        ip = &s;
        owns = false;
    }
    void set_input(std::istream *p) {
        close();
        ip = p;
        owns = true;
    }

private:
    void close() { if (owns) delete ip; }
    std::istream *ip;                 // pointer to input stream
    bool owns;                        // ip = `new` istream-derived obj
    Token ct { Kind::end, "", 0 };    // current token
    unsigned int parsed_line_ct {0};  // lines of parsed input
};


// Given that every use of TokenStream from X11-11 must have an attendant error
//   count, symbol/name table, and now for X11-12, parsed line count, it made
//   sense to bundle all these along with the parsing functions into a new
//   class.
class Calculator {
public:
    Calculator() : ts{std::cin} {}
    Calculator(std::istream &s) : ts{s} {}
    Calculator(std::istream *p) : ts{p} {}

    ~Calculator() {}

    void calculate();
    void set_input(std::istream &s) { ts.set_input(s); error_ct = 0; }
    void set_input(std::istream *p) { ts.set_input(p); error_ct = 0; }
    unsigned int errors() { return error_ct; }

#ifdef DEBUG
    void PrintNameTable() {
        for (auto &x : name_table)
            std::cout << '"' << x.first << "\", " << x.second << std::endl;
    }
#endif

private:
    TokenStream ts;
    unsigned int error_ct {0};
    std::map<const std::string, double> name_table {
        {"pi", 3.1415926535897932385},
        {"e", 2.7182818284590452354}
    };

    double prim(bool get);
    double term(bool get);
    double expr(bool get);
    double error(const std::string &s);
};


#ifdef DEBUG
const char *PrintableKind(Kind kind);
#endif


}  // namespace X11_12


#endif  // X11_12_CALCULATOR_HH

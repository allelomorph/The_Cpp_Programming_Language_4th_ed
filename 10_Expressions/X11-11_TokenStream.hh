#ifndef X11_11_TOKENSTREAM_HH
#define X11_11_TOKENSTREAM_HH


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


namespace X11_11 {


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


// Confused by Stroustrup's use of an explicit delete in close(), as the
//   relevant destructors should handle closing ip - the only edge case that
//   comes to mind is when calling set_input and the current ip is an ifstream,
//   maybe ip->close() should be called
class TokenStream {
public:
    TokenStream(std::istream &s) : ip{&s}, owns{false} {}
    TokenStream(std::istream *p) : ip{p}, owns{true} {}

    ~TokenStream() { close(); }

    Token get();                           // read and return next token
    const Token &current() { return ct; }  // most recently read token

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
    std::istream *ip;               // pointer to input stream
    bool owns;
    Token ct { Kind::end, "", 0 };  // current token
};


double prim(bool get);
double term(bool get);
double expr(bool get);
double error(const std::string &s);

#ifdef DEBUG
std::string PrintableKind(Kind kind);
#endif

extern TokenStream ts;
extern int error_ct;
extern std::map<std::string, double> name_table;


}  // namespace X11_11


#endif  // X11_11_TOKENSTREAM_HH

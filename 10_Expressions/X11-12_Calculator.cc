#include "X11-12_Calculator.hh"
#include <cctype>     // isspace
#include <iostream>
#include <string>


namespace X11_12 {


Token TokenStream::get() {
    char c;

    do {  // skip whitespace other than '\n'
        if (!ip->get(c)) {
            ct.kind = Kind::end;
            ct.string_value.clear();
            ct.number_value = 0;
            return ct;
        }
    } while (c != '\n' && std::isspace(c));

    switch (c) {
    case '\0':
        ct.kind = Kind::end;
        ct.string_value.clear();
        ct.number_value = 0;
        break;
    case '=':
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case ';':
        ct.kind = static_cast<Kind>(c);
        ct.string_value = c;
        ct.number_value = 0;
        break;
    case '\n':
        ct.kind = Kind::print;
        ct.string_value = R"(\n)";
        ct.number_value = 0;
        ++parsed_line_ct;
        break;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.': {  // braces limit scope of n_bgn/n_end
        ct.kind = Kind::number;
        ct.string_value.clear();
        ip->putback(c);            // return first char of numeric representation to stream
#ifdef DEBUG
        auto n_bgn {ip->tellg()};  // record position of first char in representation
#endif
        *ip >> ct.number_value;    // read number from stream
#ifdef DEBUG
        // using tellg with std::cin causes lseek ESPIPE failure, see:
        //   - https://stackoverflow.com/a/53982136
        // for cases where ip is a istringstream or ifstream, we can record the
        //   number's string_value by backtracking in the stream
        if (n_bgn != -1) {
            auto n_end {ip->tellg()};  // record position after last char in representation
            if (n_end == -1 && ip->eof()) {
                ip->clear();  // clear eof
                n_bgn = std::ios_base::beg;
                n_end = std::ios_base::end;
            }
            ip->seekg(n_bgn);          // return to beginning of representation
            while (ip->tellg() != n_end && ip->get(c))
                ct.string_value += c;  // record representation
        }
#endif
        break;
    }
    default:  // name, name=, or error
        // Stroustrup's exmple ignores unrecognized tokens, need to return an
        //   error instead
        if (std::isalpha(c)) {
            ct.kind = Kind::name;
            ct.string_value = c;
            while (ip->get(c)) {
                if (std::isalnum(c)) {
                    ct.string_value += c;
                } else {
                    ip->putback(c);
                    break;
                }
            }
            ct.number_value = 0;
        }
        break;
    }
#ifdef DEBUG
    std::cout << "ct.kind: " << PrintableKind(ct.kind) <<
        " ct.string_value: \"" << ct.string_value <<
        "\" ct.number_value: " << ct.number_value << std::endl;
#endif
    return ct;
}


double Calculator::prim(bool get) {
    if (get)
        ts.get();  // read next token

    switch (ts.current().kind) {
    case Kind::number: {  // floating point constant
        double v {ts.current().number_value};
        ts.get();
        return v;
    }
    case Kind::name: {
        double &v {name_table[ts.current().string_value]};
        if (ts.get().kind == Kind::assign)
            v = expr(true);
        return v;
    }  // without case braces v defined twice in same scope
    case Kind::minus:
        return -prim(true);
        break;
    case Kind::lp: {
        auto e {expr(true)};
        if (ts.current().kind != Kind::rp)
            return error("')' expected");
        ts.get();  // eat ')'
        return e;
    }
    default:
        break;
    }
    return error("primary expected");
}


double Calculator::term(bool get) {
    double left {prim(get)};

    while (true) {
        switch (ts.current().kind) {
        case Kind::mul:
            left *= prim(true);
            break;
        case Kind::div:
            if (auto d {prim(true)}) {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            goto ParseEnd;
            break;
        }
    }
ParseEnd:
    return left;
}


double Calculator::expr(bool get) {
    double left {term(get)};

    while (true) {
        switch (ts.current().kind) {
        case Kind::plus:
            left += term(true);
            break;
        case Kind::minus:
            left -= term(true);
            break;
        default:
            goto ParseEnd;
            break;
        }
    }
ParseEnd:
    return left;
}


double Calculator::error(const std::string &s) {
    ++error_ct;
    std::cerr << "error on line " << ts.line_n() << ": " << s << std::endl;
    return 1;
}


void Calculator::calculate() {
    while (true) {
        ts.get();
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        std::cout << expr(false) << std::endl;
    }
}


#ifdef DEBUG
const char *PrintableKind(Kind kind) {
    switch (kind) {
    case Kind::name:   return "name";
    case Kind::number: return "number";
    case Kind::end:    return "end";
    case Kind::plus:   return "plus";
    case Kind::minus:  return "minus";
    case Kind::mul:    return "mul";
    case Kind::div:    return "div";
    case Kind::print:  return "print";
    case Kind::assign: return "assign";
    case Kind::lp:     return "lp";
    case Kind::rp:     return "rp";
    default:
        break;
    }
    return "";
}
#endif


}  // namespace X11_11

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
    case '.': {  // braces limit scope of repr_len
        ct.kind = Kind::number;
        int repr_len {0};
        for (ct.string_value.clear(); std::isdigit(c) || c == '.'; ++repr_len) {
                ct.string_value += c;
                if (!ip->get(c))
                    break;
        }
        ip->putback(c);
        for (auto i {repr_len - 1}; i >= 0; --i)
            ip->putback(ct.string_value[i]);
        *ip >> ct.number_value;    // read number from stream
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

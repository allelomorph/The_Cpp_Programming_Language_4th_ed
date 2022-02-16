#include <iostream>

// Test file for X10-7 C / C++ file comments removal

/**
 * function - short description
 *
 * long description long description long description long description long
 *   description long description long description long description long
 *   description long description long description long description long
 *   description long description long description long description
 *
 * @parameter: param description
 * @parameter: param description
 *
 * Return: return description
 */
template <typename T>
void function(T object) {
    (void)object;
}


int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    // " appearing as char literal
    std::cout << '"' << '"' << std::endl;

    // comment symbols in multichar literal do not activate (with -Wno-multichar)
    std::cout << '//' << ' ' << '/*' << std::endl;
    std::cout << '\\' << ' ' << '\\\\' << std::endl;

    // normal string
    std::cout << "test" << std::endl;

    // strings with comment symbols
    std::cout << "//" << std::endl;
    std::cout << "/* */" << std::endl;

    // strings with escaped quotes
    std::cout << "\"test\"" << std::endl;
    std::cout << "\"\\" << std::endl;

    // raw string with default delimiter
    std::cout << R"("test")" << std::endl;
    std::cout << R"(\"test\")" << std::endl;
    std::cout << R"("\"\\")" << std::endl;

    // raw strings with arbitrary delimiters
    std::cout << R"--("test")--" << std::endl;
    std::cout << R"***("test")***" << std::endl;
    std::cout << R"/("test")/" << std::endl;
    std::cout << R"(("test"))" << std::endl;

    // raw strings with comment symbols as delimiters
    std::cout << R"//("test")//" << std::endl;
    std::cout << R"/*("test")/*" << std::endl;
    std::cout << R"*/("test")*/" << std::endl;

    // raw string delimiter can't be followed by \" or '"' as it deactivates
    //   the closing "; \ is an invalid delimiter char
    // std::cout << R"\("test")\" << std::endl;
    // std::cout << R"'("test")'"' << std::endl;
    std::cout << R"'("test")'" << std::endl;  // OK

    // raw string remains unterminated until )[delim]" detected
    std::cout << R"//("test")**" << std::endl; )//" << std::endl;

    // newlines in raw string
    std::cout << R"(
// comment in raw string

/* comment in raw string
*/

)" << std::endl;
    // can assume that compiler will not allow newlines in non-raw string
    // std::cout << "
// " << std::endl;

    // // first deactivates /*, //, and "
    // above and below lines legal, but need to compile with -Wno-comment
    /* /* first deactivates /*, //, ", ignores \n
// asdf
*/
    // " after /* does not deactivate */
    // /*std::cout << "/* */" << std::endl;

    // other character type strings:
    std::cout << u8"test" << std::endl;
    std::cout << u"test" << std::endl;
    std::cout << U"test" << std::endl;
    std::cout << L"test" << std::endl;

    // other character type raw strings
    std::cout << u8R"("test")" << std::endl;
    std::cout << uR"("test")" << std::endl;
    std::cout << UR"("test")" << std::endl;
    std::cout << LR"("test")" << std::endl;
}

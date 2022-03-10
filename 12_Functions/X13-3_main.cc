#include <iostream>
#include <string>
#include <cstdarg>
#include <type_traits>


namespace X13_3 {

// Handling arbitrary number of names by:
// (1) using a variadic template

// Base case is needed for varaidic template construction, even if call to
//   SayHello_VT(args...) is conditional on testing `if (sizeof...(args))`
void SayHello_VT() {}


// The static_assert is a simple compile-time check for the type of args,
//   but this could also be done entirely in template metaprogramming, see:
//   - https://stackoverflow.com/questions/39659127/restrict-variadic-template-arguments
template <typename T, typename ...Types>
void SayHello_VT(T arg, Types ...args) {
    static_assert(std::is_convertible<char *, T>::value,
                  "All parameters must be convertible a C string.");
    std::cout << "Hello, " << arg << '!' << std::endl;
    SayHello_VT(args...);
}


// (2) using an initializer list:
template <typename T>
void SayHello_IL(std::initializer_list<T> names) {
    static_assert(std::is_convertible<char *, T>::value,
                  "Initializer list must be convertible to a C string.");
    for (auto &x : names)
        std::cout << "Hello, " << x << '!' << std::endl;
}


// (3) using C stdarg.h:
// The type given to va_arg() cannot (?) be determined by a template,
//   so there is no guarantee that it will be printable. For example,
//   `std::string`s do not print this way, unless the caller knows to pass
//   *.c_str()
void SayHello_CSA(unsigned int name_ct, ...) {
    va_list names;
    va_start(names, name_ct);
    for (unsigned int i {0}; i < name_ct; ++i) {
        // assert
        std::cout << "Hello, " << va_arg(names, const char *) << '!' << std::endl;
    }
    va_end(names);
}

}  // namespace X13_3


int main() {
    X13_3::SayHello_VT("Aaaa", "Bbbb", "Cccc", "Dddd", "Eeee");  // const char *
    X13_3::SayHello_VT(std::string{"Aaaa"},
                       std::string{"Bbbb"}, std::string{"Cccc"},
                       std::string{"Dddd"}, std::string{"Eeee"});
    std::cout << std::endl;

    X13_3::SayHello_IL({"Aaaa", "Bbbb", "Cccc", "Dddd", "Eeee"});
    X13_3::SayHello_IL({std::string{"Aaaa"},
                       std::string{"Bbbb"}, std::string{"Cccc"},
                       std::string{"Dddd"}, std::string{"Eeee"}});
    std::cout << std::endl;

    X13_3::SayHello_CSA(5, "Aaaa", "Bbbb", "Cccc", "Dddd", "Eeee");
    // prints garbage
    X13_3::SayHello_CSA(5, std::string{"Aaaa"},
                       std::string{"Bbbb"}, std::string{"Cccc"},
                       std::string{"Dddd"}, std::string{"Eeee"});
    // must give va_arg() exactly the type it expects, as in C
    X13_3::SayHello_CSA(5, std::string{"Aaaa"}.c_str(),
                       std::string{"Bbbb"}.c_str(), std::string{"Cccc"}.c_str(),
                       std::string{"Dddd"}.c_str(), std::string{"Eeee"}.c_str());
}

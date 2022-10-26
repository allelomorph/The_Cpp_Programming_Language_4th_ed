#ifndef TYPE_NAME_HH
#define TYPE_NAME_HH

// While templates can be (forward) declared, when making a static library the
//   definition should not be in a separate .cc/.cpp file, as until a template
//   is used in the compiled code, it is not instantiated. Distribute the header
//   instead, see:
//   - https://bytes.com/topic/c/answers/161232-howto-make-template-class-part-static-library

// typeid(obj).name() return is implementation-dependent; with g++ the names
//   are "mangled" to ensure unique identification of overloaded functions.
//   Object names can be demangled, also in an implementation-specific manner.
//   With GNU, that could be at the command line with `c++filt`, or in c++ code
//   with (__cxxabiv1)abi::__cxa_demangle(), see:
//   - https://stackoverflow.com/a/4465907
//   - http://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html
//   - https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html
//   - https://en.wikipedia.org/wiki/Name_mangling
//   - https://www.cplusplus.com/forum/beginner/175177/#msg866884


#if __cplusplus < 201103L
#error "type_name<>() requires at least C++11 to use"
#endif

// C++11 solution adapted from:
//   - https://stackoverflow.com/a/20170989

#include <type_traits>  // remove_reference
#include <typeinfo>     // typeid
#ifndef _MSC_VER
#    include <cxxabi.h>  // abi::__cxa_demangle
#endif  // not MSVC
#include <memory>       // unique_ptr
#include <string>
#include <cstdlib>      // free


template <class T>
std::string type_name() {
    typedef typename std::remove_reference<T>::type TR;
#ifndef _MSC_VER
    std::unique_ptr<char, void(*)(void*)> demangled (
            abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                nullptr, nullptr),
            std::free);
    std::string result { demangled.get() };
#else   // MSVC
    std::string result { typeid(TR).name() };
#endif
    if (std::is_const<TR>::value)
        result += " const";
    if (std::is_volatile<TR>::value)
        result += " volatile";
    if (std::is_lvalue_reference<T>::value)
        result += "&";
    else if (std::is_rvalue_reference<T>::value)
        result += "&&";
    return result;
}


#endif  // TYPE_NAME_HH

#ifndef TYPENAME_HH
#define TYPENAME_HH


#ifndef __GNUC__
#error This header should be compiled with g++, as it uses cxxabi.h
#endif


#include <typeinfo>
#include <cxxabi.h>  // abi::__cxa_demangle


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


template <typename T>
const char *TypeName(const T &lvr) {
    return abi::__cxa_demangle(typeid(lvr).name(), nullptr, nullptr, nullptr);
}


template <typename T>
const char *TypeName(const T &&rvr) {
    auto o {rvr};
    return abi::__cxa_demangle(typeid(o).name(), nullptr, nullptr, nullptr);
}


#endif  // TYPENAME_HH

#ifndef TYPENAME_HH
#define TYPENAME_HH


// While templates can be (forward) declared, when making a static library the
//   definition should not be in a separate .cc/.cpp file, as until a template
//   is used in the compiled code, it is not instantiated. Distribute the header
//   instead, see:
//   - https://bytes.com/topic/c/answers/161232-howto-make-template-class-part-static-library

#if __cplusplus < 201103L

#error "typeName requires at least C++11 to use"

#elif __cplusplus < 201703L

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

// C++11 solution adapted from:
//   - https://stackoverflow.com/a/20170989

#include <type_traits>  // remove_reference
#include <typeinfo>     // typeid
#    ifndef _MSC_VER
#include <cxxabi.h>  // abi::__cxa_demangle
#    endif  // not MSVC
#include <memory>       // unique_ptr
#include <string>
#include <cstdlib>      // free

template <class T>
std::string typeName() {
    typedef typename std::remove_reference<T>::type TR;
#    ifndef _MSC_VER
    std::unique_ptr<char, void(*)(void*)> demangled (
            abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                nullptr, nullptr),
            std::free);
    std::string result { demangled.get() };
#    else   // MSVC
    std::string result { typeid(TR).name() };
#    endif
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

#else   // C++17 and above

// C++17 solution adapted from:
//  - https://stackoverflow.com/a/59522794

// __GNUC__ must be 8 and above for __PRETTY_FUNCTION__ return to be constexpr

#include <string_view>

namespace impl {

template <typename T>
[[nodiscard]] constexpr std::string_view rawTypeName() {
#    ifndef _MSC_VER
    return __PRETTY_FUNCTION__;
#    else   // MSVC
    return __FUNCSIG__;
#    endif  // MSVC
}

struct TypeNameFormat {
    std::size_t prefix_sz { 0 };
    std::size_t total_extra_chars { 0 };
};

constexpr TypeNameFormat type_name_format {
    []() constexpr {
        TypeNameFormat ret;
        std::string_view sample { rawTypeName<int>() };
        ret.prefix_sz = sample.find("int");
        ret.total_extra_chars = sample.size() - 3;
        return ret;
    }() };
static_assert(type_name_format.prefix_sz != std::string_view::npos,
              "Unable to determine the type name format on this compiler.");

template <typename T>
static constexpr std::string_view type_name_storage {
    []() constexpr {
        constexpr std::string_view raw_type_name { rawTypeName<T>() };
        return std::string_view {
            raw_type_name.data() + type_name_format.prefix_sz,
                raw_type_name.size() - type_name_format.total_extra_chars };
    }() };

}  // namespace impl

template <typename T>
[[nodiscard]] constexpr std::string_view typeName() {
    return impl::type_name_storage<T>;
}

template <typename T>
[[nodiscard]] constexpr const char *typeNameCstr() {
    return impl::type_name_storage<T>.data();
}

#endif  // C++17 and above


#endif  // TYPENAME_HH

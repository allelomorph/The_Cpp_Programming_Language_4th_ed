#include <iostream>
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <cxxabi.h>  // abi::__cxa_demangle
#include <type_traits>
#include <string>
#include <tuple>


// see: - https://codeyarns.com/tech/2020-09-19-macro-to-check-c-compiler-and-version.html
const std::string CppVerString() {
	switch (__cplusplus) {
	case 199711L: return "C++98";
	case 201103L: return "C++11";
	case 201402L: return "C++14";
	case 201703L: return "C++17";
	case 202002L: return "C++20";
	default: break;
	}
	return "";
}


// handy list of various C++ implemntation's compiler macros:
//   - https://dev.to/tenry/predefined-c-c-macros-43id
// more complete list:
//   - https://sourceforge.net/p/predef/wiki/Home/
const std::string CppImplementationString() {
	std::string impl;
#ifdef __linux__
	impl = "Linux and Linux-derived";
#endif
#ifdef __ANDROID__
	impl = "Android";
#endif
#ifdef __APPLE__
	impl = "Darwin (macOS and iOS)";
#endif
#ifdef _WIN32
	impl = "Windows (32- and 64-bit)";
#endif
#ifdef _WIN64
	impl = "Windows 64-bit";
#endif
#ifdef _MSC_VER
	impl = "Visual Studio";
#endif
#ifdef __GNUG__
	impl = "g++";
#endif
#ifdef __clang__
        impl = "clang";
#endif
#ifdef __EMSCRIPTEN__
	impl = "emscripten";
#endif
#ifdef __MINGW32__
	impl = "MinGW 32, MinGW-w64 32-bit";
#endif
#ifdef __MINGW64__
	impl = "MinGW-w64 64-bit";
#endif
	return impl;
}


template<typename T>
void PrintNemericTypeTraits(std::ostream &os, T &v) {
	// C++17: std::is_integral_v<T> == std::is_integral<T>::value
	if (!std::is_integral<T>::value &&
	    !std::is_floating_point<T>::value) {
		std::cerr << abi::__cxa_demangle(typeid(v).name(), nullptr,
						 nullptr, nullptr) <<
			" is not a numeric type!" << std::endl;
		return;
	}
	// `sizeof(type)` as in C, but also `sizeof expr` is possible
        os << std::setw(20) << abi::__cxa_demangle(
		typeid(v).name(), nullptr, nullptr, nullptr) << " - " <<
		"size: " << std::setw(2) << sizeof(T) <<
		" B   alignment: " << std::setw(2) << alignof(T) <<
		" B   min: ";
	if (typeid(v).hash_code() == typeid(char).hash_code()) {
		os << std::setw(20) << static_cast<int>(
			std::numeric_limits<T>::min()) <<
			"   max: " <<
			std::setw(20) << static_cast<int>(
				std::numeric_limits<T>::max()) <<
			std::endl;
	} else {
	        os << std::setw(20) << std::numeric_limits<T>::min() <<
			"   max: " <<
			std::setw(20) << std::numeric_limits<T>::max() <<
			std::endl;
	}
}


int main() {
	// Tuples seem to be the main STL container for hetergenous types
	std::tuple<bool, char, short, int, long, long long,
		   float, double, long double,
		   unsigned, unsigned long> type_examples {
		false, 0, 0, 0, 0, 0,
		0.0, 0.0, 0.0,
		0, 0};

	std::cout << CppVerString() << " implementation: " <<
		CppImplementationString() << '\n' << std::endl;

	// Manually iterating through the tuple - it looks like as with
	//   joining or splitting strings, it is harder in C++ than in Python.
	//   Here, get<> can only take a const, so passing a variable i will not
	//   work, and one needs to resort to templating; see:
	//   - https://stackoverflow.com/a/6894436
	//   - https://www.geeksforgeeks.org/how-to-iterate-over-the-elements-of-an-stdtuple-in-c/
	// Although it apparently gets easier in C++17/20:
	//   - https://stackoverflow.com/a/54641400
	PrintNemericTypeTraits(std::cout, std::get<0>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<1>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<2>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<3>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<4>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<5>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<6>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<7>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<8>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<9>(type_examples));
	PrintNemericTypeTraits(std::cout, std::get<10>(type_examples));
}

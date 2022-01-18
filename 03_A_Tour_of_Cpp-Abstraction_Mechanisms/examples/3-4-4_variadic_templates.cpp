/**
 * 3.4.4 Variadic Templates
 */


/////////// begin file main.cpp
#include <iostream>
#include <typeinfo>


template<typename T>
void _print(T arg) {
	std::cout << typeid(arg).name() << ":";
	if (typeid(arg).hash_code() == typeid(bool).hash_code())
		arg ? std::cout << "true " : std::cout << "false ";
	else
		std::cout << arg << " ";
}


/*
 * Stroustrup's example uses an overload with no parameters to serve as the
 * base case for the recursive call to va_print, once args is exhausted.
 */
// C-like in that it must be declared/defined before template to be called in it
void va_print() {}


template<typename T, typename ...Types>
void va_print(T arg, Types ...args) {
	_print(arg);       // use current arg
	va_print(args...);  // recurse, in next frame `arg` becomes first in `args`
}


// some examples show a base case that takes one param, not zero
/*
 * perhaps in the previous example, in the second to last frame, Types is void,
 * which then causes the overloaded va_f1 to be called
 */
// more in-depth with varaidic templates:
// https://eli.thegreenplace.net/2014/variadic-templates-in-c/
template<typename T>
T va_sum(T arg) {
	return arg;
}

template<typename T, typename ...Types>
T va_sum(T arg, Types ...args) {
	return arg + va_sum(args...);
}


// note: in C++17, fold expressions were introduced, which can streamline variadic template syntax:
// template<typename ...Values>
// auto va_sum(Values const &...values) {
// 	return (values + ...);
// }
// above uses right associativity: v1 + (v2 + v3)
// simply put ellipsis on the left for left associativity: (... + values)
// see https://www.fluentcpp.com/2021/03/12/cpp-fold-expressions/


int main() {
	std::cout << "va_print(1, 2.2, \"test\", false): " << std::endl;
	va_print(1, 2.2, "test", false);
	std::cout << std::endl;

	std::cout << "va_print(0.2, 'C', \"C++\", 3, 2, true): " << std::endl;
	va_print(0.2, 'C', "C++", 3, 2, true);
	std::cout << std::endl;

	// 2.2 becomes 2 in this example
	std::cout << "va_sum(-1, 2.2, 3, true): " <<
		va_sum(-1, 2.2, 3, true) << std::endl;

	std::cout << "va_sum(1.3, 2.2, true): " <<
		va_sum(1.3, 2.2, true) << std::endl;

	std::cout << "va_sum(1, 2, 3): " <<
		va_sum(1, 2, 3) << std::endl;
}
/////////// end file main.cpp

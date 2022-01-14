/**
 * 2.2.2 Types, Variables, and Arithmetic
 */

#include <complex>
#include <vector>
#include <iostream>

/*
 * Using simple function overloading to create a function that can take
 * parameters of many types. Once one learns templates, they may be a better
 * solution for functions that can take a wide range of parameter types.
 */
// Another resource to test object classes is <typeinfo>'s typeid().name() and typeid().hash_code()

const std::string type_name(const char param) {
	(void)param;
	return "char";
}
const std::string type_name(const signed char param) {
	(void)param;
	return "signed char";
}
const std::string type_name(const unsigned char param) {
	(void)param;
	return "unsigned char";
}
const std::string type_name(const /*signed */int param) {
	(void)param;
	return "int";
}
const std::string type_name(const unsigned int param) {
	(void)param;
	return "unsigned int";
}
// compiler recommends using fixed width types after C++11
const std::string type_name(const int64_t/*long int*/ param) {
	(void)param;
	return "long int";
}
const std::string type_name(const uint64_t/*long unsigned int*/ param) {
	(void)param;
	return "long unsigned int";
}
const std::string type_name(const float param) {
	(void)param;
	return "float";
}
const std::string type_name(const double param) {
	(void)param;
	return "double";
}
const std::string type_name(const long double param) {
	(void)param;
	return "long double";
}
const std::string type_name(const bool param) {
	(void)param;
	return "bool";
}

int main() {
	double d1 = 2.3;  // C-style syntax
	double d2 {2.3};  // initializer list format

	int i1 = 7.2;  // value autoconverted to 7 when using =
	// int i2 {7.2};  // throws assignment error
	// int i3 = {7.2};  // throws assignment error, =  is redundant

	std::complex<double> z1 = 1;
	std::complex<double> z2 = {d1, d2};
	std::complex<double> z3 = {1, 2};  // = is optional with init list

	std::cout << "complex<double> z1: " << z1 << "\n";
	std::cout << "complex<double> z2: " << z2 << "\n";
	std::cout << "complex<double> z3: " << z3 << "\n";

	std::vector<int> v {1, 2, 3, 4, 5};

	std::cout << "i1: " << i1 << "\n";

	// auto will determine a type to best fit the value
	auto _b = true;
	auto _c = 'x';
	auto _i = 123;
	auto _d = 1.2;
	auto _z = sqrt(_i);

	std::cout << type_name(_b) << " _b: " << _b << std::endl;
	std::cout << type_name(_c) << " _c: " << _c << std::endl;
	std::cout << type_name(_i) << " _i: " << _i << std::endl;
	std::cout << type_name(_d) << " _d: " << _d << std::endl;
	std::cout << type_name(_z) << " _z: " << _z << std::endl;
}

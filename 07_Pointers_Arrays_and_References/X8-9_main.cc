#include <iostream>


// pass by value, should use copy constructor, hence variable at differennt
//   address
void f(char c) {
	std::cout << "char '" << c << "' @ " << static_cast<void *>(&c)
		  << std::endl;
}


// pass by reference, should use move constructor, allows direct manipulation
//   of original object
void g(char &c) {
	std::cout << "char '" << c << "' @ " << static_cast<void *>(&c)
		  << std::endl;
}


void h(const char &c) {
	std::cout << "char '" << c << "' @ " << static_cast<void *>(
		&(const_cast<char &>(c))) << std::endl;
}


int main() {
	char c {'~'};

	std::cout << "char c in main: '" << c <<
		"' @ " << static_cast<void *>(&c) << std::endl;

	std::cout << "f(c)" << std::endl;
	f(c);

	std::cout << "g(c)" << std::endl;
	g(c);

	std::cout << "h(c)" << std::endl;
	h(c);
}

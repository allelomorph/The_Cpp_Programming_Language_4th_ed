#include <iostream>
#include <limits>


int main() {
	if (std::numeric_limits<char>::is_signed)
		std::cout << "signed";
	else
		std::cout << "unsigned";
	std::cout << std::endl;
}

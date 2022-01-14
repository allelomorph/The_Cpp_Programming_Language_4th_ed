/**
 * 2.2.5 Pointers, Arrays, Loops
 */

#include <iostream>

int main() {
	// C-like array without using <array>
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// C-like for loop is valid,
	for (auto i = 0; i < 10; ++i)
		std::cout << "arr[" << i << "]: " << arr[i] << " ";
	std::cout << std::endl;

	// but C++11 offers a range-for statement
	for (auto x : arr)  // for each i in arr
		std::cout << x << " ";
	std::cout << "\n\n";

	// range-for can be used with references as well
	// here it is not necessary to load each value of `arr` into `x`
	for (auto &x : arr) {
		std::cout << "`x` refers to `arr` value @ " << &x << std::endl;
		++x;
	}

	std::cout << "arr after modifying each value:" << std::endl;
	for (auto x : arr)
		std::cout << x << " ";
	std::cout << std::endl;
}

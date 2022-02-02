#include <iostream>


// Using C-sytle strings to remain consistent with chapter content, could
//   instead use idiomatic `std::string (&arr)[12]`
// References to (fixed-size) arrays, see:
//   - https://stackoverflow.com/a/5724184
//   - https://stackoverflow.com/a/10008405
void PrintStrArray_0(const char *(&arr)[12]) {
	for (std::size_t i = 0; i < 12; ++i)
		std::cout << arr[i] << std::endl;
}


// deomonstration of how C-style arrays decay to pointers to first element
void PrintStrArray_1(const char **arr, std::size_t arr_sz) {
	for (std::size_t i = 0; i < arr_sz; ++i)
		std::cout << arr[i] << std::endl;
}


int main() {
	const char *months[12] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};

	for (auto &s : months)
		std::cout << s << std::endl;
	std::cout << std::endl;

	PrintStrArray_0(months);
	std::cout << std::endl;

	PrintStrArray_1(months, 12);
        std::cout << std::endl;
}

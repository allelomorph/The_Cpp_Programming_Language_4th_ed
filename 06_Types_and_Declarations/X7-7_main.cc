#include <iostream>
#include <iomanip>  // setw


int main() {
	std::cout << "Integer and Hexadcimal Values of Printable ASCII " <<
		"Characters:\n" << std::endl;

	// ASCII ' ' (32) to '~' (126), printed in 4 cols of 34
	int chars_to_print {'~' - ' '};
	int cols {4};
	int rows {(chars_to_print / cols) + 1};  // + 1 for remainder

	for (auto col_n {0}; col_n < cols; ++col_n)
		std::cout << "char  int   hex | ";
	std::cout << std::endl;
	for (auto col_n {0}; col_n < cols; ++col_n)
		std::cout << "__________________";
	std::cout << std::endl << std::endl;

	char c {' '};
	for (auto row_n {0}; row_n < rows; ++row_n) {
		for (auto col_n {0}; col_n < cols; ++col_n) {
			int temp_c {c + (rows * col_n)};
			if (temp_c > '~')
				break;
			if (col_n != 0) std::cout << "  ";
			std::cout << " '" << static_cast<char>(temp_c) <<
				"'  " << std::setw(3) << std::dec << temp_c <<
				"  0x" << std::hex << temp_c << ' ';
		}
		++c;
		std::cout << std::endl;
	}
}

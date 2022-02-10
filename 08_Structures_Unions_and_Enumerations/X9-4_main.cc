#include <iostream>

#include "X9-4_Date.hh"


int main() {
	using namespace X9_4;

	struct Date date_1 {1367, 5, 13};
	struct Date date_2;
	struct Date date_3;

	std::cout << "Enter date (YYYY MM DD):" << std::endl;
	if (!(std::cin >> date_3))
		return 1;

	std::cout << date_1 << std::endl;
	std::cout << date_2 << std::endl;
	std::cout << date_3 << std::endl;
}

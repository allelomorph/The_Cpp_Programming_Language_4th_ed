#include "X5-6_UserProfile.h"
#include <iostream>


int main() {
        UserProfile up1;
	UserProfile up2;

	std::cout << "Enter name:";
	std::string name;
        getline(std::cin, name);   // allows for spaces in name string
	up1.name(name);

	std::cout << "Enter age:";
	int age;
	std::cin >> age;
	up1.age(age);

	std::cout << "Enter name and age in '{\"name\", age}' format:";
	std::cin >> up2;
	if (!std::cin.good()) {  // read failure of up2
		std::cerr << "Read failure of up2 from std::cin" << std::endl;
		return 1;
	}

	std::cout << "UserProfile 1: " << up1 << std::endl;
	std::cout << "UserProfile 2: " << up2 << std::endl;
}

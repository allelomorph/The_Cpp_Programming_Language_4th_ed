#include <string>
#include <iostream>


int main() {
        std::string name;
	std::cout << "Enter name:";
        getline(std::cin, name);   // allows for spaces in name string

        int age;
	std::cout << "Enter age:";
	std::cin >> age;

	std::cout << "Name: \"" << name << "\" age: " << age << std::endl;
}

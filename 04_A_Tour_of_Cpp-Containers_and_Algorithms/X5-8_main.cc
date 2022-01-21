#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


int main() {
	std::vector<std::string> v = { "Kant", "Plato", "Aristotle",
				       "Kierkegard", "Hume" };

	for (auto &x : v)
		std::cout << x << ' ';
	std::cout << std::endl;

	// using default operator<
        std::sort(v.begin(), v.end());
	// equivalent to:
	// std::sort(v.begin(), v.end(), std::less<std::string>());
	// Should one want to begin down the rabbit hole of locale-based string collation:
	//   - https://stackoverflow.com/a/23281505
	//   - https://docs.microsoft.com/en-us/globalization/locale/sorting-and-string-comparison

	for (auto &x : v)
		std::cout << x << ' ';
	std::cout << std::endl;
}

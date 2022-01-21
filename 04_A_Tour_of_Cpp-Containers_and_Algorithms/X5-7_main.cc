#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	std::vector<int> v = { 5, 9, -1, 200, 0 };

	for (auto &x : v)
		std::cout << x << ' ';
	std::cout << std::endl;

	// using default operator<
        std::sort(v.begin(), v.end());
	// equivalent to:
	// std::sort(v.begin(), v.end(), std::less<int>());

	for (auto &x : v)
		std::cout << x << ' ';
	std::cout << std::endl;
}

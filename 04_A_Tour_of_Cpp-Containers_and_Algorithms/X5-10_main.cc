#include <fstream>
#include <iostream>
#include <iomanip>  // setw
#include <vector>
#include <cerrno>
#include <cstring>  // strerror
#include <cassert>


int main() {
	std::string filename = "X5-9_test_file";

	// Needs manual errno checking, see X5-9_main.cc
	std::ifstream ifs(filename);
	if (errno) {
		std::cerr << "Failure to open file '" << filename << "': " <<
			strerror(errno) << std::endl;
		return 1;
	}

	std::vector<int> v;
	int i;
        while (ifs >> i) v.push_back(i);
	assert(v.size() == 10000);

	std::cout << "Read a vector of " << v.size() << " ints from file '"
		  << filename << "':" << std::endl;
	for (auto &x : v) {
		std::cout << std::setw(7) << x;
		if (x % 10 == 9) std::cout << std::endl;
	}
}

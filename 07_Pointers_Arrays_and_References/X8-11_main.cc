#include <iostream>
#include <set>
#include <string>
#include <cstring>  // strcasecmp


int main() {
	// STL sets naturally have the required traits: no duplicate values, and
	//   are stored sorted
	std::set<std::string> tokens;
	std::string s;

	while (std::cin >> s) {
		// `s == "Quit"` would be case sensitive
		// strcasecmp is a POSIX extension and not totally portable
		if (strcasecmp(s.c_str(), "Quit") == 0) break;
		tokens.insert(s);
	}

	for (auto &x : tokens)
		std::cout << '\'' << x << "' ";
}

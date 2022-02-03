#include <iostream>
#include <string>
#include <cstring>  // strstr, strlen
#include <regex>


// count appearances of substring using Regular Expressions
int CountSubstrMatches_RE(std::string needle, std::string haystack) {
	std::regex re { needle };
	auto matches_begin = std::sregex_iterator {
		haystack.begin(), haystack.end(), re};
	auto matches_end = std::sregex_iterator {};
	return std::distance(matches_begin, matches_end);
}


// count appearances of substring using std:string.find()
int CountSubstrMatches(std::string needle, std::string haystack) {
	int match_ct {0};
	std::size_t i { haystack.find(needle) };
	while (i != std::string::npos) {
		++match_ct;
		i = haystack.find(needle, i + needle.size());
	}
	return match_ct;
}


// count appearances of substring using C standard library
int CountSubstrMatches(char *needle, char *haystack) {
	int match_ct {0};
	char *match { std::strstr(haystack, needle) };
	while (match != nullptr) {
		++match_ct;
		match = std::strstr(match + std::strlen(needle), needle);
	}
	return match_ct;
}


int main() {
	const std::string test_s_n {"ab"};
	const std::string test_s_h {"xabaacbaxabb"};
	// + 1 each for NULL terminating null bytes
	const char test_cs_n[3] {"ab"};
	const char test_cs_h[13] {"xabaacbaxabb"};

	std::cout << CountSubstrMatches_RE(test_s_n, test_s_h) << std::endl;
	std::cout << CountSubstrMatches(test_s_n, test_s_h) << std::endl;
	std::cout << CountSubstrMatches(test_cs_n, test_cs_h) << std::endl;
}

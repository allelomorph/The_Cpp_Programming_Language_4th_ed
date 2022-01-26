#include <iostream>
#include <iomanip>     // setw
#include <fstream>
#include <stdexcept>
#include <cstring>     // strerror
#include <regex>
#include <string>
#include "X6-5_UniformRandIntGen.hh"


double UniformRandDouble (float f_low, float f_high) {
	UniformRandIntGen rnd_whole(std::round(f_low), std::round(f_high));
	UniformRandIntGen rnd_dec(0, 1000);

	int dec = rnd_dec();
	int pow_10 = 0;
	for (int temp = dec; temp; temp /= 10) pow_10++;
	int whole = rnd_whole();
	return (whole < 0) ?
		whole - (dec / std::pow(10, pow_10)) :
		whole + (dec / std::pow(10, pow_10)) ;
}


void CreateRegexTestFile(std::string filename) {
	std::ofstream ofs(filename);
	// C-like manual checking of stream creation failure; idomatic STL
	//   solutions introduced with C++17's <filesystem>
	if (errno && errno != ENOENT) {
		throw std::runtime_error("Failure to create test file '" +
					 filename + "': " + strerror(errno));
	}

	// '!' 33 to '~' 126
	UniformRandIntGen rnd_char(33, 126);
        UniformRandIntGen rnd_int(-100, 100);
	UniformRandIntGen rnd_char_ct(1, 10);
	UniformRandIntGen rnd_binary(0, 1);

	// 20 lines of random tokens interspersed with ints and floats
	for (auto i = 0; i < 20; i++) {
		for (auto i = 0; i < 10; i++) {
			if (rnd_binary()) {
				int char_ct = rnd_char_ct();
				for (auto i = 0; i < char_ct; i++)
					ofs << static_cast<char>(rnd_char());
		        } else if (rnd_binary()) {
				ofs << rnd_int();
			} else {
				ofs << UniformRandDouble(-100.0, 100.0);
			}
			if (rnd_binary()) ofs << ' ';
		}
		ofs << std::endl;
	}
}


// C-like access of command line args, is there a more idomatic STL way?
int main(int argc, char *argv[]) {
	std::string filename;
	if (argc < 2) {
		std::cout << "No file name provided for regex test. " <<
			"Using default 'X6-5_test_file'." << std::endl;
		filename = "X6-5_test_file";
	} else {
		filename = argv[1];
	}

	std::ifstream ifs(filename);
        if (errno == ENOENT && filename == "X6-5_test_file") {
		std::cout << "Default test file '" << filename <<
			"' not found, creating one now..." << std::endl;
		CreateRegexTestFile(filename);
		ifs.open(filename);
	} else if (errno) {
		throw std::runtime_error("Failure to open test file '" +
					 filename + "': " + strerror(errno));
	}

	// example use of regex iterator taken from:
	//   - https://en.cppreference.com/w/cpp/regex
	// C++ regex supports multiple engines, default is
	//   std::regex_constants::ECMAScript, see cheatsheet:
	//   - https://cpprocks.com/files/c++11-regex-cheatsheet.pdf
	int line_n = 0;
	for (std::string line; getline(ifs, line); line_n++) {
		std::cout << "\nIn line " << std::setw(2) << line_n <<
			": '''" << line << "''':\n" << "Found:";
		std::regex fp_regex("-?\\d+\\.\\d+");
		auto matches_bgn =
			std::sregex_iterator(line.begin(), line.end(),
					     fp_regex);
		auto matches_end = std::sregex_iterator();
		for (std::sregex_iterator i = matches_bgn;
		     i != matches_end; ++i) {
			std::cout << ' ' << (*i).str();  // *i is std::smatch
		}
		std::cout << std::endl;
	}
}

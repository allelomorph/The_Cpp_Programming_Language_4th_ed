#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>  // setw
#include <cerrno>
#include <cstring>  // strerror


int main() {
	std::string filename = "X5-9_test_file";

	// In C, [f]open() have many failure conditions, but here the STL
	//   throws no exeptions on file open error, plus both ifs.is_open() and
	//   ifs.good() return true afterward... need to resort to C-like errno
	//   checking? see:
	//   - https://stackoverflow.com/questions/17491178/- how to check for failure in STL?
	std::ofstream ofs(filename);
	if (errno) {
		std::cerr << "Failure to open file '" << filename << "': " <<
			strerror(errno) << std::endl;
		return 1;
	}

	for (int i = 0, row = 0; i < 10000; ++row) {
		for (int col = 0; i < 10000 && col < 10; ++col) {
		        ofs << std::setw(7) << i;
			i++;
		}
	        ofs << std::endl;
	}
}

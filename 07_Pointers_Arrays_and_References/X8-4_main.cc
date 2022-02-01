#include "X6-5_UniformRandIntGen.hh"
#include <iostream>
#include <cstring>   // strlen
#include <cstdlib>   // abs


int main() {
	// using C-like char array over idiomatic use of std:string,
	//   as most examples in chapter 7 do
	// dummy text from `man gcc`
	const char test_buf[] = {R"(       When you invoke GCC, it normally does preprocessing, compilation, assembly and linking.  The "overall
       options" allow you to stop this process at an intermediate stage.  For example, the -c option says not
       to run the linker.  Then the output consists of object files output by the assembler.

       Other options are passed on to one or more stages of processing.  Some options control the preprocessor
       and others the compiler itself.  Yet other options control the assembler and linker; most of these are
       not documented here, since you rarely need to use any of them.

       Most of the command-line options that you can use with GCC are useful for C programs; when an option is
       only useful with another language (usually C++), the explanation says so explicitly.  If the description
       for a particular option does not mention a source language, you can use that option with all supported
       languages.

       The usual way to run GCC is to run the executable called gcc, or machine-gcc when cross-compiling, or
       machine-gcc-version to run a specific version of GCC.  When you compile C++ programs, you should invoke
       GCC as g++ instead.
)"
	};

	UniformRandIntGen<std::size_t> rnd_idx{0, strlen(test_buf) - 1};
	const char *p1 {test_buf + rnd_idx()};
	const char *p2 {test_buf + rnd_idx()};

	// pointer arithmetic, if using C-like iterator could also subtract two
	//   iterator values
	std::cout << "char *p1 and char *p2 are " << std::abs(p1 - p2) <<
		" characters apart." << std::endl;

}

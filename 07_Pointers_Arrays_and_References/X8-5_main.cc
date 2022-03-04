#include "UniformRandIntGen.hh"
#include <iostream>
#include <cstdlib>   // abs


int main() {
	// using C-like int array over idiomatic use of std:array<int>,
	//   as chapter 7 is discussing plain arrays
	constexpr int arr_sz {200};
	const int int_arr[arr_sz] {0};
	UniformRandIntGen<> rnd_idx {0, arr_sz - 1};
	const int *p1 {int_arr + rnd_idx()};
	const int *p2 {int_arr + rnd_idx()};

	// pointer arithmetic, if using C-like iterator could also subtract two
	//   iterator values
	// note that pointer arithmetic values are n * sizeof(member type) bytes
	std::cout << "int *p1 and int *p2 are " << std::abs(p1 - p2) <<
		" integers (array positions) apart." << std::endl;
}

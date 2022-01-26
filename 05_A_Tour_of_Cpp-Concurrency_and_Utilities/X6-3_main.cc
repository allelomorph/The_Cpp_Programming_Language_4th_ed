#include <iostream>
#include <chrono>
#include <cmath>


// Using godbolt.org and g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, -O2 only
//   saves 8 lines of assembly in this case, and no appreciable rum time savings


int main() {
	auto tc0 = std::chrono::high_resolution_clock::now();
	double sqrt_sum = 0.0;
	for (int i = 1; i < 100; ++i)
		sqrt_sum += sqrt(i);
	std::cout << "Sum of square roots of integers from 1 to 100: " << sqrt_sum;
	auto tc1 = std::chrono::high_resolution_clock::now();
	std::cout << " calculated in: " <<
		std::chrono::duration_cast<std::chrono::microseconds>(
			tc1 - tc0).count() << " microsec" << std::endl;
}

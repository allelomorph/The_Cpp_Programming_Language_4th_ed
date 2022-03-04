#include <iostream>
#include <iomanip>
#include "UniformRandIntGen.hh"


namespace X10_3 {

	// Duff's Device, see:
	//   - https://en.wikipedia.org/wiki/Duff%27s_device
	//   - https://www.geeksforgeeks.org/duffs-device-work/
	//   - https://www.lysator.liu.se/c/duffs-device.html
	// Stroustrup example will not compile with g++ 9.3.0, even with
	//   -std=c++11 and -Wno-implicit-fallthrough. Comparing with the
	//   geeksforgeeks example, the issue seems to be the use of a
	//   do-while. Modified to use while loop:

	void DuffDeviceCopy(int *dest, int *src, std::size_t size)
	{
	        std::size_t rounds { size / 8 };

		switch (size % 8) {
		case 0:
			while (rounds) {
				--rounds;
				*dest++ = *src++;
	        case 7:
			*dest++ = *src++;
		case 6:
			*dest++ = *src++;
		case 5:
			*dest++ = *src++;
		case 4:
			*dest++ = *src++;
		case 3:
			*dest++ = *src++;
		case 2:
			*dest++ = *src++;
		case 1:
			*dest++ = *src++;
			};
		}
	}

	// Reading the linked sources, it looks as though the advantage here is
	//   optimize for speed by reducing the amount of loop tests by having
	//   a loop that tests once for 8 (could be any amount) iterations of
        //   the same instruction, and using the switch case to jump midway
        //   into the loop to execute the remainder of iterations after dividing
        //   by the amount the statement is repeated.

}  // namespace X10_3


int main() {
	UniformRandIntGen<> rnd_i(0, 10000);
	constexpr std::size_t size {10};
	int arr1[size];
	int arr2[size];

	for (auto &x : arr1)
		x = rnd_i();

	for (auto &x : arr1)
		std::cout << std::setw(5) << x << ' ';
	std::cout << std::endl;

	X10_3::DuffDeviceCopy(arr2, arr1, size);

	for (auto &x : arr2)
		std::cout << std::setw(5) << x << ' ';
	std::cout << std::endl;
}

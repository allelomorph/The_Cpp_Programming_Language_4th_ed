#include <random>
#include <iostream>
#include <iomanip>   // setw
#include <typeinfo>
#include <cxxabi.h>  // abi::__cxa_demangle
#include <map>
#include <cmath>     // round


template<typename RNGT>
void PrintNormalDist(int mean, int std_dist, RNGT rng) {
	// random.h:1966 "result_type must be a floating point type"
	std::normal_distribution<double> nd(mean, std_dist);

	// typeid(obj).name() return is implementation-dependent; with g++ the
	//   names are "mangled" to ensure unique identification of overloaded
	//   functions. Object names can be demangled, also in an implementation-
	//   specific manner. With GNU, that could be at the command line with
	//   `c++filt`, or in c++ code with (__cxxabiv1)abi::__cxa_demangle(),
        //   see:
	//   - https://stackoverflow.com/a/4465907
	//   - http://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html
	//   - https://en.wikipedia.org/wiki/Name_mangling
	//   - https://www.cplusplus.com/forum/beginner/175177/#msg866884
	std::cout << "Normal distribution with generator type: " <<
		abi::__cxa_demangle(typeid(RNGT).name(),
				    nullptr, nullptr, nullptr) << std::endl;

	// Mimicing Stroustrup's example in 5.6.3 runs the risk of causing
	//   invalid reads out of the range of the histogram vector. See comment
	//   code at end of file. Using instead the map example from:
	//   - https://en.cppreference.com/w/cpp/numeric/random/normal_distribution

	// as with Python dict, elements of a map are tuples of two (pairs in STL)
	std::map<int, int> hist{};
	for(int n = 0; n < 10000; ++n) {
		++hist[std::round(nd(rng))];
	}
	// .first and .second are pair-specific syntax
	for(auto p : hist) {
		std::cout << std::setw(5) << p.first << ' ' <<
			std::string(p.second/20, '*') << '\n';
	}
}


int main() {
	// Stroustrup 5.6.3 uses default_random_engine,
	std::default_random_engine re;
	// but:
	//   - https://stackoverflow.com/a/38245134
	//   - https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
	// both use the following engine:
	std::random_device rd{};
	std::mt19937 gen{rd()};
	//   - cppreference.com <random> #Predefined generators

	int mean;  // average value generated
        int sd;    // standard deviation, average distance of values from the mean
	std::cout << "Enter mean: ";
	std::cin >> mean;
	if (!std::cin.good()) {
		std::cout << "Value read error!" << std::endl;
		return 1;
	}
	std::cout << "Enter standard deviation: ";
	std::cin >> sd;
	if (!std::cin.good()) {
		std::cout << "Value read error!" << std::endl;
		return 1;
	}
	if (sd < 0) {
		std::cout << "Standard deviation cannot be negative" << std::endl;
		return 1;
	}

	PrintNormalDist(mean, sd, re);
	PrintNormalDist(mean, sd, gen);
}


/////// (flawed) solution mimicing 5.6.3
/*
	std::vector<size_t> hist(30);
	// return of nd() will be floating point, but implicitly cast
	for(int i = 0; i < 200; ++i) {
		++hist[nd(rng)];
	}
	for(size_t i = 0; i < hist.size(); ++i) {
		std::cout << std::setw(2) << i << ' ';
		for(size_t j = 0; j < hist[i]; ++j) std::cout << '*';
		std::cout << std::endl;
	}
*/

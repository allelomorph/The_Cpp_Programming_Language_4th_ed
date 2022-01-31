#ifndef X6_5_UNIFORMRANDINTGEN_HH
#define X6_5_UNIFORMRANDINTGEN_HH


#include <random>

template<class IntType = int>
class UniformRandIntGen {
public:
        UniformRandIntGen(IntType low, IntType high) :rng{rd()}, dist{low, high} { }
	int operator()() { return dist(rng); }
private:
	// The default_random_engine (minstd_rand0 or
	//   std::linear_congruential_engine<std::uint_fast32_t, 16807, 0,
	//   2147483647> in the GNU implementation) seems to not be
	//   seeded/produces the same values at runtime for every compilation.
	//   Using Marsenne instead.
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng;          // random-number engine used (Mersenne-Twister)
	std::uniform_int_distribution<IntType> dist;
};


#endif  // X6_5_UNIFORMRANDINTGEN_HH

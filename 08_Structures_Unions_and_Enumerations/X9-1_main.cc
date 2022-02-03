#include <iostream>
#include <cstddef>  // offsetof


// __attribute__ ((packed)) can be used with gcc/g++ to eliminate extra space
//   in a struct, at the cost of efficiency of member access, see:
//   - https://gcc.gnu.org/onlinedocs/gcc-9.4.0/gcc/Common-Type-Attributes.html#Common-Type-Attributes


namespace X9_1 {
// alternating order of word and sub-word sized members forces the maximum
//   amount of padding, as the word-sized members must begin at a word boundary
struct Unaligned {
	bool b;
	long l;
	char c;
	double d;
	int i;
	long double ld;
};

// If member order prevents a member straddling a word boundary as much as
//   possible, by grouping word-divisible members together, padding can be reduced
struct Aligned {
	long l;          // 8 bytes (1 word)
	double d;        // 8 bytes
	long double ld;  // 16 bytes
	int i;           // 4 bytes
	char c;          // 1 byte
	bool b;          // 1 byte
};
// What is not clear is why sizeof(struct Aligned) == 48 and not 40, the next
//   multiple of 8 after 38 (total of members) - is it padded to double word size?

}  // namespace X9_1


int main() {
	std::cout << "sizeof(struct Unaligned): " <<
		sizeof(struct X9_1::Unaligned) << std::endl;
	std::cout <<
		"offsetof(struct Unaligned, b): " <<
		offsetof(struct X9_1::Unaligned, b) << std::endl <<
		"offsetof(struct Unaligned, l): " <<
		offsetof(struct X9_1::Unaligned, l) << std::endl <<
		"offsetof(struct Unaligned, c): " <<
		offsetof(struct X9_1::Unaligned, c) << std::endl <<
		"offsetof(struct Unaligned, d): " <<
		offsetof(struct X9_1::Unaligned, d) << std::endl <<
		"offsetof(struct Unaligned, i): " <<
		offsetof(struct X9_1::Unaligned, i) << std::endl <<
		"offsetof(struct Unaligned, ld): " <<
		offsetof(struct X9_1::Unaligned, ld) << std::endl <<
		std::endl;
	std::cout << "sizeof(struct Aligned): " <<
		sizeof(struct X9_1::Aligned) << std::endl;
        std::cout <<
		"offsetof(struct Aligned, l): " <<
		offsetof(struct X9_1::Aligned, l) << std::endl <<
		"offsetof(struct Aligned, d): " <<
		offsetof(struct X9_1::Aligned, d) << std::endl <<
		"offsetof(struct Aligned, ld): " <<
		offsetof(struct X9_1::Aligned, ld) << std::endl <<
		"offsetof(struct Aligned, i): " <<
		offsetof(struct X9_1::Aligned, i) << std::endl <<
		"offsetof(struct Aligned, c): " <<
		offsetof(struct X9_1::Aligned, c) << std::endl <<
		"offsetof(struct Aligned, b): " <<
		offsetof(struct X9_1::Aligned, b) << std::endl <<
}

#include <iostream>


// Honestly not sure what Stroustrup is asking for here, is it that we use an
//   STL container other than a vector, such as a list? Or that we find a
//   single equation that creates the series 4, 5, 9, 17, and 12 when iterated?
// Neither seems relevant to the chapter's subject matter, so far as I can tell.
// One (inefficient) cheat is simply supplment the loop with a second control flow:
int main() {
	int val {4};
	for (auto i {0}; i < 5; ++i) {
		std::cout << val << " ";
		switch (val) {
		case 4:  val += 1; break;
		case 5:  val += 4; break;
		case 9:  val += 8; break;
		case 17: val -= 5; break;
		default: break;
		}
	}
	std::cout << std::endl;
}

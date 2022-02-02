#include <iostream>


void IntValueSwap(int *a, int *b) {
	if (a == nullptr || b == nullptr) {
		std::cerr << "IntValueSwap: nullptr parameter"
			  << std::endl;
	} else {
		// C-like swap by copying
		int temp {*a};
		*a = *b;
		*b = temp;
	}
}


// one advantage of a reference is that it cannot exist without a target,
//   so no need to filter bad inputs here
void IntValueSwap(int &a, int &b) {
	// swapping can be done by moving/using rvalue references, versus the
	//   potentially costly copying/using lvalue references
	// move() does not actually move, but instead creates a rvalue reference,
	//   equivalent to static_cast<T&&>(v) for T v
	int temp {std::move(a)};
	a = std::move(b);
	b = std::move(temp);
}


int main() {
	int i1 {1}, i2 {2}, i3 {3}, i4 {4};

	std::cout << "Initialized: i1 = 1, i2 = 2, i3 = 3, i4 = 4;" << std::endl;

	IntValueSwap(&i1, &i2);
	IntValueSwap(i3, i4);

	std::cout << "After call to `IntValueSwap(&i1, &i2)`, or "
		"`IntValueSwap(int *a, int *b)`, i1 == " << i1 <<
		" i2 == " << i2 << std::endl;
	std::cout << "After call to `IntValueSwap(i3, i4)`, or "
		"`IntValueSwap(int &a, int &b)`, i3 == " << i3 <<
		" i4 == " << i4 << std::endl;
}

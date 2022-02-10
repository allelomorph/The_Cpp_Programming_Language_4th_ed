#include <iostream>
#include <iomanip>


int main() {
	// deliberately declaring outside STL container to allow for separated
	//   memory addresses
	char c1, c2, c3, c4, c5;
	int i1, i2, i3, i4, i5;
	void *vp1 {nullptr}, *vp2 {nullptr}, *vp3 {nullptr},
	        *vp4 {nullptr}, *vp5 {nullptr};

	std::cout << std::setw(10) << "char *" << " - size: " << sizeof(char *) <<
		" alignment: " << alignof(char *) <<
		" (char alignment: " << alignof(char) << ')' << std::endl;
	std::cout << "example: char c1, c2, c3, c4, c5;\n"
		  "Variables at memory addresses:" << std::endl;
	// operator<< interprets a char * as a string, so we cast to void *
	std::cout << "c1 @ " << static_cast<void *>(&c1) << std::endl;
	std::cout << "c2 @ " << static_cast<void *>(&c2) << std::endl;
	std::cout << "c3 @ " << static_cast<void *>(&c3) << std::endl;
	std::cout << "c4 @ " << static_cast<void *>(&c4) << std::endl;
	std::cout << "c5 @ " << static_cast<void *>(&c5) << std::endl;

	std::cout << std::setw(10) << "int *" << " - size: " << sizeof(int *) <<
		" alignment: " << alignof(int *) <<
		" (int alignment: " << alignof(int) << ')' << std::endl;
	std::cout << "example: int i1, i2, i3, i4, i5;\n"
		  "Variables at memory addresses:" << std::endl;
	std::cout << "i1 @ " << &i1 << std::endl;
	std::cout << "i2 @ " << &i2 << std::endl;
	std::cout << "i3 @ " << &i3 << std::endl;
	std::cout << "i4 @ " << &i4 << std::endl;
	std::cout << "i5 @ " << &i5 << std::endl;

	std::cout << std::setw(10) << "void *" << " - size: " << sizeof(void *) <<
		" alignment: " << alignof(void *) << std::endl;
	std::cout << "example: void *vp1 {nullptr}, *vp2 {nullptr}, "
		"*vp3 {nullptr}, *vp4 {nullptr}, *vp5 {nullptr};\n"
		"void * are conventionally initialized to NULL / (void *)0 in C or nullptr in C++:"
		  << std::endl;
	std::cout << "vp1 @ " << vp1 << std::endl;
	std::cout << "vp2 @ " << vp2 << std::endl;
	std::cout << "vp3 @ " << vp3 << std::endl;
	std::cout << "vp4 @ " << vp4 << std::endl;
	std::cout << "vp5 @ " << vp5 << std::endl;

	std::cout << "But can be assigned pointers of any other type:" << std::endl;
	vp1 = &c1;
	std::cout << "vp1 = &c1; vp1 @ " << vp1 << std::endl;
	vp2 = &c2;
	std::cout << "vp2 = &c2; vp2 @ " << vp2 << std::endl;
	vp3 = &c3;
	std::cout << "vp3 = &c3; vp3 @ " << vp3 << std::endl;
	vp4 = &c4;
	std::cout << "vp4 = &c4; vp4 @ " << vp4 << std::endl;
	vp5 = &c5;
	std::cout << "vp5 = &c5; vp5 @ " << vp5 << std::endl;
	std::cout << std::endl;
	vp1 = &i1;
	std::cout << "vp1 = &i1; vp1 @ " << vp1 << std::endl;
	vp2 = &i2;
	std::cout << "vp2 = &i2; vp2 @ " << vp2 << std::endl;
	vp3 = &i3;
	std::cout << "vp3 = &i3; vp3 @ " << vp3 << std::endl;
	vp4 = &i4;
	std::cout << "vp4 = &i4; vp4 @ " << vp4 << std::endl;
	vp5 = &i5;
	std::cout << "vp5 = &i5; vp5 @ " << vp5 << std::endl;
}

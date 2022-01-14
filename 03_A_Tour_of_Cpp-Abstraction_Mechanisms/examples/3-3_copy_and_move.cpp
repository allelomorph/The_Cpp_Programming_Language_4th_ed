/**
 * 3.3.1 Copying Containers
 * 3.3.2 Moving Containers
 */


/////////// begin file Vector.h
#include <initializer_list>
#include <algorithm>  // std::copy


class Vector {
private:
	double *elem;  // points to an array of sz doubles
	int sz;
public:
	Vector() :elem{new double[0]}, sz{0} {}
	Vector(int s)                           // constructor: establish invariant, acquire resources
		:elem{new double[s]}, sz{s} {
			for (int i = 0; i != s; ++i)
				elem[i] = 0;
		}
	Vector(std::initializer_list<double> lst)       // adapted from 3.2.1.3
		:elem{new double[lst.size()]},
		 sz{static_cast<int>(lst.size())} {
			 std::copy(lst.begin(), lst.end(), elem);
		}
	~Vector() { delete[] elem; }            // destructor: release resources

	Vector(const Vector &a);                       // copy constructor
	Vector &operator=(const Vector &a);            // copy assignment

	double &operator[](int i) { return elem[i]; }  // subscript variable
//	const double &operator[](int i) const;         // subscript constant

	int size() const { return sz; }
};
/////////// end file Vector.h


/////////// end file Vector.cpp
// #include "Vector.h"


Vector::Vector(const Vector &a)                 // copy constructor
	:elem{new double[a.sz]},
	 sz{a.sz} {
	for (int i = 0; i != sz; ++i)
		elem[i] = a.elem[i];
}


Vector &Vector::operator=(const Vector &a) {    // copy assignment
	double *p = new double[a.sz];

	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;  // delete previous elements
	elem = p;  // pointer to first element in new array
	sz = a.sz;
	return *this;
}
/////////// end file Vector.cpp


/////////// begin file main.cpp
#include <iostream>
#include <array>
// #include "Vector.h"


int main() {
	Vector v1 = {1, 2, 3};  // initializer list construction

	Vector v2{v1};  // copy initialization

	Vector v3;
	v3 = v2;        // copy assignment

	std::array<Vector, 3> arr{v1, v2, v3};
	for (auto x : arr) {
	        // std::begin and std::end not in this scope, can't nest range-for loops?
		for (auto y = 0; y != x.size(); ++y)  // for (auto y : x)
			std::cout << x[y] << std::endl;
	}
}
/////////// end file main.cpp

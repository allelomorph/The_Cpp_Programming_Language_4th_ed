/**
 * 3.4.1 Parameters Types
 */


/////////// begin file Vector.h
#include <initializer_list>
#include <algorithm>  // std::copy


template<typename T>
class Vector {
private:
        T *elem;  // points to an array of sz type T elements
	int sz;
public:
	Vector(int s);                          // constructor: establish invariant, acquire resources
	Vector(std::initializer_list<T> lst)    // adapted from 3.2.1.3
		:elem{new T[lst.size()]},
		 sz{static_cast<int>(lst.size())} {
			 std::copy(lst.begin(), lst.end(), elem);
		}

	~Vector() { delete[] elem; }            // destructor: release resources

	Vector(const Vector &a);                       // copy constructor
	Vector &operator=(const Vector &a);            // copy assignment

//	Vector(Vector &&a);                            // move constructor
//	Vector &operator=(Vector &&a);                 // move assignment

	T &operator[](int i);                          // subscript variable
	const T &operator[](int i) const;              // subscript constant
	int size() const { return sz; }

	T *begin() {                                   // used in range-for
		return sz ? &elem[0] : nullptr;        // &(elem[0])
	}
	T *end() { return begin() + sz; }              // used in range-for
};
/////////// end file Vector.h


/////////// begin file Vector.cpp
// #include "Vector.h"
#include <stdexcept>
#include <iostream>


template<typename T>
Vector<T>::Vector(int s) {
	if (s < 0) throw std::out_of_range("Vector::Vector(int)");  // Stroustrup example has `Negative_size{}`
	elem = new T[s];
	sz = s;
}


template<typename T>
Vector<T>::Vector(const Vector &a)                 // copy constructor
	:elem{new T[a.sz]},
	 sz{a.sz} {
		 for (int i = 0; i != sz; ++i)
			 elem[i] = a.elem[i];
}


template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &a) {    // copy assignment
        T *p = new T[a.sz];

	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;  // delete previous elements
	elem = p;  // pointer to first element in new array
	sz = a.sz;
	return *this;
}


template<typename T>
const T &Vector<T>::operator[](int i) const {
        if (i < 0 || size() <= i)
		throw std::out_of_range("Vector::operator[]");
	return elem[i];
}


/*
Examples of begin() and end() outside of Vector class:

template<typename T>
T* begin(Vector<T> &x) {
	return x.size() ? &x[0] : nullptr;     // &(x[0])
}


template<typename T>
T* end(Vector<T> &x) {
	return begin(x) + x.size();
}
*/
/////////// end file Vector.cpp


/////////// begin file main.cpp
// #include <iostream>
#include <string>
// #include "Vector.h"


int main() {
	Vector<int> vi = {1, 2, 3};         // initializer list construction
	Vector<char> vc = {'a', 'b', 'c'};
	Vector<std::string> vs = {"one", "two", "three"};

// How to create a vector or array of vectors of different types? C++17 std::any or ::variant?

	for (auto x : vi)
		std::cout << x << std::endl;

	for (auto x : vc)
		std::cout << x << std::endl;

	for (auto x : vs)
		std::cout << x << std::endl;
}
/////////// end file main.cpp

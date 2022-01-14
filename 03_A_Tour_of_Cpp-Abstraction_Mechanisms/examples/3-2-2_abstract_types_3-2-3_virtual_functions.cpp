/**
 * 3.2.2 Abstract Types
 * 3.2.3 Virtual Functions
 */


/////////// begin file Container.h
// #pragma once  // equivalent to C-like include guard

// Example of abstract class, used as an interface to its derived classes.
class Container {
public:
	// virtual functions may be overridden by definitions in derived classes
	// virtual functions `= 0` are "pure virtual," meaning that they _must_ be defined in dervied classes
	virtual double &operator[](int) = 0;
	virtual int size() const = 0;
	/*
	 * Abstract classes do not need constructors if they do not initialize data.
	 * But having a destructor is important, as objects of derived classes are
	 * likely deleted via a pointer to the base class, which then implicitly
	 * calls the appropriate destructor in the dervied class.
	 */
	virtual ~Container() {}
};
/////////// end file Container.h


/////////// end file Vector_container.h
// #include "Container.h"
#include <vector>

class Vector_container :public Container {
// private:  (class members are private by default: https://stackoverflow.com/questions/2532107/)
	std::vector<double> vd;
public:
	// using `v(s)` to engage std::vector constructor
	// `v{s}` would try to convert to a double and make a vector of vd[0] = s
	Vector_container(int s) :vd(s) {}
	~Vector_container() {}

	double &operator[](int i) { return vd[i]; }  // calls std::vector operator[]
	int size() const { return vd.size(); }  // calls std::vector size()
};
/////////// end file Vector_container.h


/////////// begin file List_container.h
// #include "Container.h"
#include <list>

class List_container :public Container {
	std::list<double> ld;
public:
        List_container() {}
	// compiler creates initializer_list objects out of brace initializations
	List_container(std::initializer_list<double> il) :ld{il} {}
	~List_container() {}

	double &operator[](int i);  // can't use `return ld[i];`, as std::list has no operator[]
	int size() const { return ld.size(); }
};
/////////// end file List_container.h


/////////// begin file List_container.cpp
// #include List_container.h
#include <stdexcept>


double &List_container::operator[](int i) {
	// forward traversal of doubly-linked list ld
	for (auto &x : ld) {
		if (i == 0) return x;
		--i;
	}
	throw std::out_of_range("List container");
}
/////////// end file List_container.cpp


/////////// begin file main.cpp
#include <iostream>
// #include "List_container.h"
// #include "Vector_container.h"

/*
 * By passing the base (abstract) class as a parameter, use() can be called for
 * every derived class of Container, which all must have both size() and operator[],
 * since they are decalred as pure virtual in the definition of Container.
 */
void use(Container &c) {
	const int sz = c.size();

	// not using range-for to demonstrate both size() and operator[]
	for (int i = 0; i != sz; ++i)
		std::cout << c[i] << std::endl;
}


int main() {
	List_container lc = {1, 2, 3, 4};
	Vector_container vc = Vector_container(3);

	/*
	 * lc and vc both contain pointers to a vtbl, or virtual function table,
	 * which has pointers to the derived class versions of all base class
	 * virtual functions.
	 */
	// use() defined with a reference parameter, so objects passed by reference.
	// ( see https://stackoverflow.com/a/410857 )
	use(lc);
	use(vc);
}
/////////// end file main.cpp

/**
 * 3.4.2 Function Templates
 * 3.4.3 Function Objects
 */


/////////// begin file Less_than.h
// Function object, or "functor":
template<typename T>
class Less_than {
public:
	// val would normally be private, made public here for testing
        const T val;                         // value to compare against

	Less_than(const T &v) :val(v) {}     // (copy) constructor?
	bool operator()(const T &x) const {  // call operator
		return x < val;
	}
};
/////////// end file Less_than.h


/////////// begin file main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
// #include "Less_than.h"


Less_than<int> lti {42};                    // lti(i) will compare i to 42 using <
Less_than<std::string> lts {"cat"};         // lts(s) will compare s to "cat" using <


// Functors can be called like functions:
void f1(int n, const std::string &s) {
	bool b1 = lti(n);
	bool b2 = lts(s);

	std::cout << lti.val << " < " << n << " == " << b1 << std::endl;
	std::cout << lts.val << " < " << s << " == " << b2 << std::endl;
}


// Functors can be used as parameters to algorithms:
// Is this a way to use functional programming in C++?
template<typename C, typename P>
int count(const C &c, P pred) {
	int cnt = 0;
	for (const auto &x : c)
		if (pred(x))
			++cnt;
	return cnt;
}


void f2(const std::vector<int> &v, const std::list<std::string> &l,
	int x, const std::string &s) {
	// Less_than creates an object passed as P to count(C, P)
	std::cout << "Number of values less than " << x
		  << ": " << count(v, Less_than<int>{x})
		  << std::endl;
	std::cout << "Number of values less than " << s
		  << ": " << count(l, Less_than<std::string>{s})
		  << std::endl;
}


// Function objects/functors can also be implicitly created with lambda expressions
void f3(const std::vector<int> &v, const std::list<std::string> &l,
	int x, const std::string &s) {
	// object passed as P to count(C, P) created in syntax
	// `[&](int a){ return a < x; }` lambda expression
	//     `[&]` capture list (local names used accessed by reference)
	//         `[&x]` explicitly access x by reference
	//         `[]` capture nothing
	//         `[=]` local names by value
	std::cout << "Number of values less than " << x
		  << ": " << count(v, [&](int a){ return a < x; })
		  << std::endl;
	std::cout << "Number of values less than " << s
		  << ": " << count(l, [&](const std::string &a){ return a < s; })
		  << std::endl;
}


int main() {
	int i1 = 41, i2 = 43, i3 = -42;
	std::string s1 = "bat", s2 = "rat", s3 = "d";

	std::vector<int> v1 = {i1, i2, i3};

	std::list<std::string> l1 = {s1, s2, s3};

	f1(i1, s1);
	f1(i2, s2);
	f1(i3, s3);

	std::cout << std::endl;

	f2(v1, l1, lti.val, lts.val);
	f2(v1, l1, 10, "at");

	std::cout << std::endl;

	f3(v1, l1, lti.val, lts.val);
	f3(v1, l1, 10, "at");
}
/////////// end file main.cpp

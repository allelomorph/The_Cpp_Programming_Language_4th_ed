// The debate on pragma once vs include guards seems to go back and forth, see:
//   - https://stackoverflow.com/questions/1143936/pragma-once-vs-include-guards
#ifndef X5_6_USERPROFILE_HH
#define X5_6_USERPROFILE_HH


#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class UserProfile {
private:
	std::string _name;
	int _age;

	std::string &UniformStrSpacing(std::string &s) {
		// split and rejoin to eliminate potential whitespace between tokens
		std::istringstream iss(s);
		std::vector<std::string> tokens;
		for (std::string t; iss >> t; ) tokens.push_back(t);
		std::ostringstream oss("");
		std::vector<std::string>::iterator it = tokens.begin();
	        oss << *it++;
		for (; it != tokens.end(); ++it) oss << ' ' << *it;
	        s = oss.str();
		return s;
	}
public:
	UserProfile() :_name{""}, _age{0} {}
	UserProfile(std::string n) :_name{UniformStrSpacing(n)}, _age{0} {}
	UserProfile(std::string n, int a) :_name{UniformStrSpacing(n)}, _age{a} {
		if (a < 0)
			throw std::out_of_range("UserProfile constructor age");
	}
	~UserProfile() {}

	// getters and setters, see:
	//   - https://stackoverflow.com/questions/51615363/
	//   - https://cpp-rendering.io/thoughts-about-getters-and-setters-in-c/
	//   - https://stackoverflow.com/questions/32625274/
	//   - https://stackoverflow.com/a/51616035
	// ampersands after function, see:
	//   - https://en.cppreference.com/w/cpp/language/member_functions,
	//       "ref-qualified member functions"
	//   - https://codexpert.ro/blog/2014/10/17/c-gems-ref-qualifiers/
	const std::string &name() const & { return _name; }
	std::string name() && { return std::move(_name); }
	void name(std::string s) { _name = UniformStrSpacing(s); }

	const int &age() const & { return _age; }
	int age() && { return std::move(_age); }
        void age(int a) {
		if (a < 0)
			throw std::out_of_range("UserProfile age");
		_age = a;
	}

	// If only accesing public members, stream operator overloads should
	//   not be declared inside the class, as they are not member functions.
	// But if name and age are private or protected, they would be declared
	//   as `friend` funcs, see:
	//     - https://stackoverflow.com/questions/10744787/
	//     - https://en.cppreference.com/w/cpp/language/friend
//        friend std::ostream &operator<<(std::ostream &os, const UserProfile &up);
//        friend std::istream &operator>>(std::istream &is, UserProfile &up);
};


// As with C, non-member functions need prototypes declared in a header to be
//   accessible to other translation units, see:
//   - https://stackoverflow.com/questions/47083328/
std::ostream &operator<<(std::ostream &os, const UserProfile &up);
std::istream &operator>>(std::istream &is, UserProfile &up);


#endif  // X5_6_USERPROFILE_HH

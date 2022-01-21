#include "X5-6_UserProfile.hh"
#include <iostream>
#include <string>
#include <sstream>


// mock JSON formatting
std::ostream &operator<<(std::ostream &os, const UserProfile &up) {
	return os << "{\"" << up.name() << "\", " << up.age() << "}";
}


// Sadly it looks like there is no C++ equivalent of Python's str.split() or
//   str.join(), and this is a commonly encountered problem - see:
//   - https://www.codecademy.com/resources/blog/bjarne-stroustrup-interview/ (#5)
//   - https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
//   - https://stackoverflow.com/questions/14265581/#14266139
//   - http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
//   - https://github.com/ekg/split

// Tokenizing could be done with strtok(), but the point of this exercise is to
//   learn the STL

// Some options for future testing could be:
//   - Boost's boost::split
//   - C++20's std::ranges::split_view
std::istream &operator>>(std::istream &is, UserProfile &up) {
	is >> std::ws; // skip leading whitespace
	char c;
	if (!is.get(c) || c != '{') {
		is.setstate(std::ios_base::failbit);
		return is;
	}

	// get '"name", age'
	std::string up_str;
        getline(is, up_str, '}');
	if (!is.good())
		return is;

	// separate elements by first comma
	std::istringstream up_iss(up_str);
	std::vector<std::string> up_tokens;
	std::string s;
	while (getline(up_iss, s, ',')) up_tokens.push_back(s);
        if (up_tokens.size() != 2) {
		is.setstate(std::ios_base::failbit);
		return is;
	}

	// cull name string from between first and second " in first element
	std::istringstream name_iss(up_tokens[0]);
	name_iss >> std::ws;
	std::string name;
	if (!name_iss.get(c) || c != '"') {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	getline(name_iss, name, '"');
	if (!name_iss.good()) {
		is.setstate(std::ios_base::failbit);
		return is;
	}

	// C++11 uses stoi, some users recommend C++17's from_chars, see:
	//   - https://stackoverflow.com/a/55875943
	int age = std::stoi(up_tokens[1]);
	up = UserProfile{name, age};

	return is;
}

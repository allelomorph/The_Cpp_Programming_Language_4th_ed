#include "X5-6_UserProfile.h"
#include <iostream>
#include <string>
#include <vector>
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
	char c1;
	// strip whitespace until first {
	do {
		is.get(c1);
	} while (std::isspace(c1));
	if (c1 == '{') {
		// get '"name", age'
		std::string up_str;
		std::getline(is, up_str, '}');
		// if (!is.good())
		if (is.rdstate() == std::ios_base::failbit ||
		    is.rdstate() == std::ios_base::eofbit)
			return is;

		// find first comma, which separates elements
		std::string::size_type cma_sz = up_str.find_first_of(',');
		if (cma_sz == std::string::npos) {
			is.setstate(std::ios_base::failbit);
			return is;
		}

		// raw element strings may contain extra whitespace
		std::string name = up_str.substr(0, cma_sz);
		std::string age_str = up_str.substr(cma_sz + 1, up_str.size());

		// trim raw name before first "
		// beware the difference between std::find and std::string::find
		std::string::size_type dblq_sz = name.find_first_of('"');
		if (dblq_sz == std::string::npos) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
	        name.erase(0, dblq_sz + 1);

		// trim raw name after second "
	        dblq_sz = name.find_first_of('"');
		if (dblq_sz == std::string::npos) {
			is.setstate(std::ios_base::failbit);
			return is;
		}
	        name.erase(dblq_sz);

		// no trimmming of whitespace between name tokens
		int age = std::stoi(age_str);
		up = UserProfile{name, age};
	} else {
		is.setstate(std::ios_base::failbit);
	}
        return is;
}


/*
		// split and rejoin name string to reduce whitespace between tokens
                std::istringstream name_iss(name);
                std::vector<std::string> name_tokens;
                for (std::string t; name_iss >> t; ) name_tokens.push_back(t);
                std::ostringstream name_oss("");
                std::vector<std::string>::iterator it = name_tokens.begin();
                name_oss << *it++;
                for (; it != name_tokens.end(); ++it) name_oss << ' ' << *it;
                name = name_oss.str();
*/

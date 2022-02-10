#include <iostream>
#include <string>
#include <array>
#include <map>
#include <locale>

#include "X9-5_Season.hh"


// Stroustrup recommends looking ahead to Chapter 39 to implent a means to assign
//   the appropriate season name strings for the user's language. Looking at the
//   examples in 39.3.2, presumably this is by creating a user-defined locale
//   facet. But given that Chapter 39 has its own set of exercises for that
//   material, here we use a much simpler approach, to focus instead on use of
//   operator overloads with an enum class.

namespace X9_5 {

        const std::array<const std::string, 4> *Season_names;

	const std::array<const std::string, 4> en_XX_Season_names {
		"spring", "summer", "autumn", "winter" };

        const std::array<const std::string, 4> da_DK_Season_names {
		u8"forår", u8"sommer", u8"efterår", u8"vinter" };

	// cannot use reference as map value, see:
	//   - https://stackoverflow.com/questions/4239253
	std::map<const std::string, const std::array<const std::string, 4> *>
	Season_names_by_C_locale_prefix {
		{"C",     &en_XX_Season_names},
		{"POSIX", &en_XX_Season_names},
		{"en_",   &en_XX_Season_names},
		{"da_",   &da_DK_Season_names}
	};

	void Set_Season_names() {
		// should return string equivalent to environment's LC_ALL or LANG
		std::string loc_name { std::locale("").name() };
		// get prefix
	        loc_name = loc_name.substr(0, loc_name.find('.'));
		Season_names = Season_names_by_C_locale_prefix[loc_name];
	}

	// need separate declarations for pre- and post- increment/decrement, see:
	//   - https://stackoverflow.com/a/46326686
	Season &operator++(Season &s) {
		if (s == Season::winter)
			s = Season::spring;
		else
			s = static_cast<Season>(static_cast<int>(s) + 1);
		return s;
	}

	Season &operator++(Season &s, int) {
		if (s == Season::winter)
			s = Season::spring;
		else
			s = static_cast<Season>(static_cast<int>(s) + 1);
		return s;
	}

	Season &operator--(Season &s) {
		if (s == Season::spring)
			s = Season::winter;
		else
			s = static_cast<Season>(static_cast<int>(s) - 1);
		return s;
	}

	Season &operator--(Season &s, int) {
		if (s == Season::spring)
			s = Season::winter;
		else
			s = static_cast<Season>(static_cast<int>(s) - 1);
		return s;
	}

	std::ostream &operator<<(std::ostream &os, Season &s) {
		// only can be out of range if cast from other type
		if (s < Season::spring || s > Season::winter)
			os.setstate(std::ios_base::failbit);
		else
			os << (*Season_names)[static_cast<int>(s)];
		return os;
	}

	std::istream &operator>>(std::istream &is, Season &s) {
		std::string token;
		is >> token;
	        for (auto i {0}; i < 4; i++) {
			if ((*Season_names)[i] == token) {
				s = static_cast<Season>(i);
				return is;
			}
		}
		is.setstate(std::ios_base::failbit);
		return is;
	}

}  // namespace X9_5

#ifndef X9_5_SEASON_HH
#define X9_5_SEASON_HH


#include <iostream>


// Stroustrup recommends looking ahead to Chapter 39 to implent a means to assign
//   the appropriate season name strings for the user's language. Looking at the
//   examples in 39.3.2, presumably this is by creating a user-defined locale
//   facet. But given that Chapter 39 has its own set of exercises for that
//   material, here we use a much simpler approach, to focus instead on use of
//   operator overloads with an enum class.

namespace X9_5 {

	enum class Season { spring, summer, autumn, winter };

	void Set_Season_names();

	// need separate declarations for pre- and post- increment/decrement, see:
	//   - https://stackoverflow.com/a/46326686
	Season &operator++(Season &s);
	Season &operator++(Season &s, int);
	Season &operator--(Season &s);
	Season &operator--(Season &s, int);

	std::ostream &operator<<(std::ostream &os, Season &s);
	std::istream &operator>>(std::istream &is, Season &s);

}  // namespace X9_5


#endif  // X9_5_SEASON_HH

#include "X9-5_Season.hh"


// Stroustrup recommends looking ahead to Chapter 39 to implent a means to assign
//   the appropriate season name strings for the user's language. Looking at the
//   examples in 39.3.2, presumably this is by creating a user-defined locale
//   facet. But given that Chapter 39 has its own set of exercises for that
//   material, here we use a much simpler approach, to focus instead on use of
//   operator overloads with an enum class.


int main() {
	using namespace X9_5;

	Set_Season_names();

        Season season {};

	std::cout << "Season season {}: " << season << std::endl;
	std::cout << "Season default (as int): " <<
		static_cast<int>(season) << std::endl;
	std::cout << "++season: " << ++season << std::endl;
	season++;
	season++;
	season++;
	std::cout << "season++ season++ season++: " << season << std::endl;
	std::cout << "--season: " << --season << std::endl;
	std::cout << "--season: " << --season << std::endl;

	Season season_2 {};
	Season season_3 {static_cast<Season>(-1)};
	Season season_4 {static_cast<Season>(4)};

	if (std::cin >> season_2)
		std::cout << season_2 << std::endl;
	std::cout << season_3 << std::endl;
	std::cout << season_4 << std::endl;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>  // strcmp


namespace X9_2 {

struct Month {
	const int days;
	const char name[10];
};

}  // namespace X9_2


int main() {
	constexpr int month_ct {12};
	const char *month_names[month_ct] {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	const int month_day_cts[month_ct] {
		31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31
	};
        const struct X9_2::Month months[month_ct] {
	        {31, "January"}, {28, "February"}, {31, "March"}, {30, "April"},
	        {31, "May"}, {30, "June"}, {31, "July"}, {31, "August"},
	        {30, "September"}, {31, "October"}, {30, "November"},
	        {31, "December"}
        };

	std::cout << std::setw(10) << "Month" << " Days" << std::endl;
	for (auto i = 0; i < month_ct; ++i) {
		std::cout << std::setw(10) << month_names[i] << ' ';
		// can't compare to literal with `== "February"` (-Werror=address)
		if (std::strcmp(month_names[i], "February") == 0) {
			std::cout << month_day_cts[i] <<
				'(' << month_day_cts[i] + 1 << ')';
		} else {
			std::cout << month_day_cts[i];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::setw(10) << "Month" << " Days" << std::endl;
	for (auto i = 0; i < month_ct; ++i) {
		std::cout << std::setw(10) << months[i].name << ' ';
		// can't compare to literal with `== "February"` (-Werror=address)
		if (std::strcmp(months[i].name, "February") == 0) {
			std::cout << months[i].days <<
				'(' << months[i].days + 1 << ')';
		} else {
			std::cout << months[i].days;
		}
		std::cout << std::endl;
	}
}

#ifndef X9_4_DATE_HH
#define X9_4_DATE_HH


#include <array>
#include <string>


// Not addressing locale in this exercise for simplicity's sake; also ignoring
//   era: AD/BC

namespace X9_4 {

	// Monday first as in ISO week date format / ISO 8601
	enum class DayOfWeek { Mo = 1, Tu, We, Th, Fr, Sa, Su };
	enum class Month {  // default int for struct packing
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};
	constexpr unsigned int months_in_year {12};
	const std::array<const unsigned int, months_in_year> days_in_month {
	        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	const std::array<const std::string, months_in_year> month_names {
	        "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	constexpr unsigned int days_in_week {7};
	const std::array<std::string, days_in_week> day_names {
		"Monday", "Tuesday", "Wednesday", "Thursday",
	        "Friday", "Saturday", "Sunday"
	};

	struct Date {
		// struct members are public by default
		// better packing could be achieved by using unsigned char for
		//   month, day, and dow, but this complicates use of >>
		unsigned int year;
	        Month month;
		unsigned int day;
		DayOfWeek dow;

		DayOfWeek DayOfWeekForDate(unsigned int year,
					   unsigned int month,
					   unsigned int day);

		Date(unsigned int y, unsigned int m,
		     unsigned int d) :year{y} {
			     if (!m || m > months_in_year)
				     throw std::out_of_range("Date.month");
			     if (!d || d > days_in_month[m - 1])
				     throw std::out_of_range("Date.day");
			     month = static_cast<Month>(m);
			     day = d;
			     dow = DayOfWeekForDate(y, m, d);
		     }
	        Date() :year{1901}, month{Month::Jan}, day{1} {
			dow = DayOfWeekForDate(1901, 1, 1);
		}
	};


	// see X5-6_UserProfile.hh for why stream operator overloads not
	//   declared inside the class/struct
	std::ostream &operator<<(std::ostream &os, const Date &date);
	std::istream &operator>>(std::istream &is, Date &date);

}  // namespace X9_4


#endif  // X9_4_DATE_HH

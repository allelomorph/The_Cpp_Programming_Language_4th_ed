#include <iostream>
#include <iomanip>

#include "X9-4_Date.hh"


namespace X9_4 {

	// Zeller's Congruence algorithm, see:
	//   - https://www.geeksforgeeks.org/zellers-congruence-find-day-date/
	DayOfWeek Date::DayOfWeekForDate(unsigned int year, unsigned int month,
					 unsigned int day) {
		switch (month) {
		case 1: month = 13; --year; break;
		case 2: month = 14; --year; break;
		default: break;
		}
		unsigned int k {year % 100};
		unsigned int j {year / 100};
		unsigned int h {
			day + (13 * (month + 1) / 5) + k + (k / 4) +
			(j / 4) + (5 * j)
		};
		return static_cast<DayOfWeek>(((h + 5) % 7) + 1);
	}


	std::ostream &operator<<(std::ostream &os, const Date &date) {
		// subscripting requires ints
		os << day_names[static_cast<int>(date.dow) - 1] << ", " <<
			month_names[static_cast<int>(date.month) - 1] << ' ' <<
			date.day << ' ' << date.year;
		return os;
	}


	std::istream &operator>>(std::istream &is, Date &date) {
		unsigned int month, day;
		// leading 0 should not be seen as octal
		if (!(is >> date.year >> std::dec >> month >> std::dec >> day))
			return is;
		if (!month || month > months_in_year)
			throw std::out_of_range("Date.month");
		if (!day || day > days_in_month[month - 1])
			throw std::out_of_range("Date.day");
		date.month = static_cast<Month>(month);
		date.day = day;
		date.dow = date.DayOfWeekForDate(date.year, month, day);
		return is;
	}

}  // namespace X9_4

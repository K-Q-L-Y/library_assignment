#include <string>
#include <iomanip>
#include "date.hpp"

using namespace std;

Date::Date() {
	time_t t = time(0);
	tm *now = localtime(&t);

	set_year(1900 + now->tm_year);
	set_month(1 + now->tm_mon);
	set_day(now->tm_mday);
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::get_year() const {
	return this->year;
}

int Date::get_month() const {
	return this->month;
}

int Date::get_day() const {
	return this->day;
}

void Date::set_year(int y) {
	year = y;
}

void Date::set_month(int m) {
	month = m;
}

void Date::set_day(int d) {
	day = d;
}

void Date::print() {
	cout << get_year() << "/" << get_month() << "/" << get_day();
}

string Date::to_string() {
	ostringstream oss;
	oss << year << "/" << setfill('0') << setw(2) \
	<< month << "/" << setfill('0') << setw(2) << day;
	return oss.str();
}

Date Date::add_days(int n)
{
	int y = get_year();
	int m = get_month();
	int d = get_day();
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	d += n;
	while (d > days[m - 1] || m > 12) {
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			days[1] = 29; // leap year
		else
			days[1] = 28;

		if (d > days[m - 1]) {
			d -= days[m - 1];
			m++;
		}
		if (m > 12) {
			m -= 12;
			y++;
		}
	}
	return Date(y, m, d);
}

Date Date::operator+(int n) {
	return this->add_days(n);
}

ostream& operator<<(ostream &os, const Date &d) {
	os << d.get_year() << "/" << setfill('0') << setw(2) << d.get_month() \
	<< "/" << setfill('0') << setw(2) << d.get_day();
	return os;
}

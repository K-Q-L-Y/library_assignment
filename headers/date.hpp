#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

using namespace std;

class Date {
	public:
		Date();
		Date(int year, int month, int day);
		void set_year(int year);
		void set_month(int month);
		void set_day(int day);
		int get_year() const;
		int get_month() const;
		int get_day() const;
		void print();
		string to_string();
		Date add_days(int days);
		Date operator+(int n);
		friend ostream& operator<<(ostream &os, const Date &d);
	private:
		int year;
		int month;
		int day;
};

#endif
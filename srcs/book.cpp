#include <iostream>
#include <iomanip>
#include "book.hpp"

using namespace std;

Book::Book(string name, int id) : name(name), id(id) {
	Date today;
	this->set_available(true);
	this->set_deadline(today);
}

string Book::get_name() const {
	return name;
}

int Book::get_id() const {
	return id;
}

bool Book::is_available() const {
	return available;
}

Date Book::get_deadline() const {
	return deadline;
}

void Book::set_deadline(Date d) {
	deadline = d;
}

void Book::set_available(bool a) {
	available = a;
}

ostream& operator<<(ostream &os, const Book b) {
	os << b.name << " (" << b.id << ")";
	return os;
}

#include <iostream>
#include "person.hpp"

using namespace std;

Person::Person(string name, string email, string id) :
	name(name), email(email), id(id) {

} 

void Person::borrow_book(Library &lib, Book& book) {
	throw runtime_error("Permission denied: cannot borrow book.");

}

void Person::return_book(Library &lib, Book &book) {
	throw runtime_error("Permission denied: cannot return book.");

}

Lst<Book> Person::search_book(Library &lib, string query) {
	throw runtime_error("Permission denied: cannot search book.");

}

void Person::add_book(Library &lib, Book& book) {
	throw runtime_error("Permission denied: cannot add book.");
}

void Person::remove_book(Library &lib, Book &book) {
	throw runtime_error("Permission denied: cannot remove book.");
}

string Person::get_name() const {
	return name;
}

string Person::get_email() const {
	return email;
}

string Person::get_id() const {
	return id;
}

void Person::print() {
	cout << "Name: " << get_name() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "ID: " << get_id() << endl;
}

bool Person::operator==(const Person &other) {
	if (this->id != other.id)
		return false;
	return true;
}
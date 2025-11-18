#include <iostream>
#include "person.hpp"

using namespace std;

Person::Person(string name, string email, int id) : name(name), email(email), id(id) {

} 

void Person::borrow(Book &book) {
	try {
		if (!(book.is_available()))
			throw runtime_error("Book not found");
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	while (true) {
		string input;
		cout << "Confirm borrow book: \"" << book.get_name() << "\"? [y/n] ";
		getline(cin, input);
		if (input == "n")
			return;
		if (input == "y") {
			Date today;
			book.set_deadline(today + 14);
			book.set_available(false);
			cout << "Book borrowed: " << book.get_name() << endl;
			cout << "Return book by: " << book.get_deadline() << " (14 days remaining)" << endl;
			return;
		}
	}	
}

void Person::search(Book &Book) {

}

string Person::get_name() const {
	return name;
}

string Person::get_email() const {
	return email;
}

int Person::get_id() const {
	return id;
}

void Person::print() {
	cout << "Name: " << get_name() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "ID: " << get_id() << endl;
}

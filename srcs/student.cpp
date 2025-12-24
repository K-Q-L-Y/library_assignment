#include <iostream>
#include "student.hpp"
#include "library.hpp"

Student::Student(string name, string email, string id) :
	Person(name, email, id) {
		role = Role::Student;
}

// void borrow_book(Library& lib, Book &book) override;

void Student::borrow_book(Library &lib, Book &book) {
	if (!book.is_available()) {
		cout << "Book not available." << endl; // todo: add borrow queue
		return;
	}
	while (true) {
		string input;
		cout << "Confirm borrow book: \"" << book.get_name() << "\"? [y/n] ";
		getline(cin, input);
		if (input == "n")
		return;
		if (input == "y")
		break;
	}

	lib.borrow_book(book);
	cout << "Book borrowed: " << book.get_name() << endl;
	cout << "Return book by: " << book.get_deadline() << " (14 days remaining)" << endl;
	// add book to student
	books.add_back(book);
}

// TODO
void return_book(Library& lib, Book &book) {
	
}

Lst<Book> Student::search_book(Library& lib, string query) {
	Lst<Book> results = lib.search_book(query);

	return results;
}

void Student::print() {
	
}
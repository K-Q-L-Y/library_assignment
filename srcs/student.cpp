#include <iostream>
#include "student.hpp"
#include "library.hpp"

Student::Student(string name, string email, string id) :
	Person(name, email, id) {
		role = Role::Student;
}

// void borrow_book(Library& lib, Book &book) override;
// void return_book(Library& lib, Book &book) override;
// Lst<Book> search_book(Library& lib, string query) override;
		
void Student::borrow_book(Library &lib, Book &book) {
	try {

		if (!lib.has_book(book) || !(book.is_available()))
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
		if (input == "y")
			break;
	}
	Date today;
	book.set_deadline(today + 14);
	book.set_available(false);
	cout << "Book borrowed: " << book.get_name() << endl;
	cout << "Return book by: " << book.get_deadline() << " (14 days remaining)" << endl;
	books.add_back(book);
}


void Student::print() {

}
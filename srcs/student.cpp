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
		lib.borrow_book(book);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return;
	}
	cout << "Book borrowed: " << book.get_name() << endl;
	cout << "Return book by: " << book.get_deadline() << " (14 days remaining)" << endl;
	// add book to student
	books.add_back(book);
}


void Student::print() {

}
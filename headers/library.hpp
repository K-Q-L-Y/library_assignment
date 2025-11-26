#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include "person.hpp"

class Library {
	public:
		Library() {};

		// manage users
		void add_user(Person &user);
		void remove_user(Person &user);
		
		// manage books
		void add_book(Book &book);
		void remove_book(Book &book);

		// services
		void borrow_book(Book &book);
		void return_book(Book &book);
		Lst<Book> search(string query); // title, author, genre
	
	
		void print_books() {
			books.print();
		}

		void print_users() {
			users.print();
		}

		bool has_book(const Book &book) {
			return books.contains(book);
		}

		bool has_user(const Person &p) {
			return users.contains(p);
		}
	private:
		Lst<Book> books;
		Lst<Person> users;
		// Lst <Record> records;
};

#endif
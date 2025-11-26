#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include "book.hpp"
#include "person.hpp"
#include "lst_utils.hpp"

class Library {
	public:
		Library();

		// manage users
		void add_user(Person &user);
		void remove_user(Person &user);
		
		// manage books
		void add_book(Book &book);
		void remove_book(Book &book);

		// services
		void borrow_book(Book &book);
		void return_book(Book &book);
		Lst<Book> search(string query);
	private:
		Lst<Book> books;
		int book_count;

		Lst<Person> users;
		int user_count;
};

#endif
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"
#include "lst_utils.hpp"
#include "book.hpp"

class Student : public Person {
	public:
		Student(string name, string email, string id);
		
		void borrow_book(Library& lib, Book &book) override;
		void return_book(Library& lib, Book &book) override;
		Lst<Book> search_book(Library& lib, string query) override;
		
	private:
		Lst<Book> books;
		int book_count;

};

#endif
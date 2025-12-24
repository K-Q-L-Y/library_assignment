#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person {
	public:
		Student(string name, string email, string id);
		
		void borrow_book(Library &lib, Book &book) override;
		// void return_book(Library &lib, Book &book) override;
		
		Lst<Book> search_book(Library& lib, string query) override;

		
		void show_books() override {
			books.print();
		}

		friend ostream& operator<<(ostream &os, Student &s) {
			os << "Name: " << s.name << "\nEmail: " << s.email
			<< "\nID: " << s.id << endl;
			return os;
		};
		
		void print() override;
		// Lst<Book> search_book(string query) override;
		
	private:
		Lst<Book> books;
};

#endif
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person {
	public:
		Student(string name, string email, string id);
		
		void borrow_book(Library &lib, Book &book) override;
		void show_books() override {
			books.print();
		}

		friend ostream& operator<<(ostream &os, Student &s) {
			os << "----------\nName: " << s.name << "\nEmail: " << s.email
			<< "\nID: " << s.id << endl;
			return os;
		};
		
		void print() override;
		// void return_book(Book &book) override;
		// Lst<Book> search_book(string query) override;
		
	private:
		Lst<Book> books;
};

#endif
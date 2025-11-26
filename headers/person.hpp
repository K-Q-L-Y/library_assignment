#ifndef PERSON_HPP
# define PERSON_HPP

#include <iostream>
#include "book.hpp"
#include "lst_utils.hpp"

class Library;

using namespace std;

class Person {
	public:
		enum class Role {
			Librarian,
			Student,
			Guest
		};

		Person(string name, string email, string id);
		virtual ~Person() {}

		string get_name() const;
		string get_id() const;
		string get_email() const;

		virtual void borrow_book(Library &lib, Book &book);
		virtual void return_book(Library &lib, Book &book);
		virtual Lst<Book> search_book(Library &lib, string query);
		
		virtual void add_book(Library &lib, Book &book);
		virtual void remove_book(Library &lib, Book &book);
		
		virtual void show_books() {};
		virtual void print();
		bool operator==(const Person &other);
		friend ostream& operator<<(ostream &os, Person &p) {
			os << "----------\nName: " << p.name << "\nEmail: " << p.email
			<< "\nID: " << p.id << endl;
			return os;
		};
	protected:
		string name;
		string email; // pls dont regex
		string id;
		Role role;
};

#endif

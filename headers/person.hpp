#ifndef PERSON_HPP
# define PERSON_HPP

#include <iostream>
#include "book.hpp"

using namespace std;

class Person {
	public:
		Person(string name, string email, int id);
		string get_name() const;
		string get_email() const;
		int get_id() const;
		void borrow(Book &book);
		void search(Book &book);
		void print();
	private:
		string name;
		string email; // pls dont regex
		int id;
};

#endif

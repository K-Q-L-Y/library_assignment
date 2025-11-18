#ifndef BOOK_HPP
#define BOOK_HPP

#include "date.hpp"

class Book {
	public:
		Book(string name, int id);
		string get_name() const;
		int get_id() const;
		bool is_available() const;
		Date get_deadline() const;
		void set_available(bool available);
		void set_deadline(Date deadline);
		friend ostream& operator<<(ostream &os, const Book b);
	private:
		string name;
		int id;
		bool available;
		Date deadline;
};

#endif
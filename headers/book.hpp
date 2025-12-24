#ifndef BOOK_HPP
#define BOOK_HPP

#include "date.hpp"

class Book {
	public:
		Book(string name, string id);
		string get_name() const;
		string get_id() const;
		bool is_available() const;
		Date get_deadline() const;
		void set_available(bool available);
		void set_deadline(Date deadline);
		bool operator==(const Book &other);
		friend ostream& operator<<(ostream &os, const Book b);
	private:
		string name;
		string id;
		bool available;
		Date deadline;
};

#endif
#include "library.hpp"

void Library::add_user(Person &user) {
	users.add_back(user);
}

void Library::remove_user(Person &user) {
	// match by id in case of dupe name
	for (int i = 0; i < users.get_size(); ++i) {
		Person cur = users.get(i);
		if (cur.get_id() != user.get_id())
		continue;
		users.remove_at(i);
		return;
	}
	throw runtime_error("User does not exist");
}

void Library::add_book(Book &book) {
	books.add_back(book);
}

void Library::remove_book(Book &book) {
// match by id in case of dupe name
	for (int i = 0; i < books.get_size(); ++i) {
		Book cur = books.get(i);
		if (cur.get_id() != book.get_id())
		continue;
		books.remove_at(i);
		return;
	}
	throw runtime_error("Book does not exist");
}
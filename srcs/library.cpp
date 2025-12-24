#include "library.hpp"
#include "utils.hpp"

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

void Library::add_book(Book book) {
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

void Library::borrow_book(Book &book) {
	vector<int> v = books.find_all(book);
	bool available = false;
	int book_index;
	for (const int &idx : v) {
		if (books.get(idx).is_available()) {
			available = true;
			book_index = idx;
			break;
		}
	}
	if (!available)
		throw runtime_error("Book currently not available");

	book.set_available(false);
	Date today;
	book.set_deadline(today + 14);
	// change availability of book in library
	books.set(book_index, book);
}

Lst<Book> Library::search_book(string query) {
	Lst<Book> ret;
	for (int i = 0; i < books.get_size(); ++i) {
		if (startswith(books.get(i).get_name(), query))
			ret.add_back(books.get(i));
	}
	return ret;
}
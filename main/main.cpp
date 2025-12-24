#include <iostream>
#include "date.hpp"
#include "library.hpp"
#include "student.hpp"
#include "utils.hpp"

using namespace std;

enum STATUS {
	HOME,
	SEARCH,
	BORROW,
	RETURN,
	ADD_BOOK,
	REMOVE_BOOK,
	ADD_USER,
	REMOVE_USER
};

int main()
{
	int status = SEARCH;
	Library lib;
	// book samples
	for (int i = 0; i < 3; ++i) {
		string name;
		string id;
		cout << "Enter book name to add: ";
		getline(cin, name);
		cout << "Enter book id: ";
		getline(cin, id);
		Book book(name, id);
		lib.add_book(book);
	}
	// string name = "Harry Potter";int id = 1;
	// Book book1(name, id);
	// lib.add_book(book1);
	// name = "Percy Jackson";id = 2;
	// Book book2(name, id);
	// name = "Lord of the Rings";id = 3;
	// Book book3(name, id);
	// name = "Microelectronics 8th Edition";id = 4;
	// Book book4(name, id);
	string query;
	Lst<Book> results;
	Person *p = new Student("Harry", "harry@gmail.com", "S1234");
	int book_idx;
	while (true) {
		string input;
		switch (status) {
			case SEARCH:
				cout << "Enter book to search: ";
				getline(cin, query);
				results = p->search_book(lib, query);
				if (results.get_size() == 0) {
					cout << "No results found" << endl;
					continue;
				}
				for (int i = 0; i < results.get_size(); ++i) {
					cout << i + 1 << ": " << results.get(i) << endl;
				}
				cout << endl;
				while (true) {
					cout << "Select book to borrow (1-" << results.get_size() << "): ";
					getline(cin, input);
					if (input.empty() || !is_numeric(input))
						continue;
						book_idx = stoi(input) - 1;
						cout << "book index = " << book_idx << endl;
						cout << "size of list = " << results.get_size() << endl;
					if (book_idx >= 0 && book_idx < results.get_size())
						break;
				}
				
				status = BORROW;
				break;
			case BORROW:
				Book book = results.get(book_idx);
				p->borrow_book(lib, book);
				cout << "Books borrwed by " << p->get_name() << endl;
				p->show_books();
				status = SEARCH;
				break;
		}

	}

	cout << "Number of books : " << lib.get_books_size() << endl;
	lib.print_books();

	cout << "Search for book: ";
	getline(cin, query);
	results = lib.search_book(query);
	if (results.get_size() == 0)
		return 0;
	Book book = results.get(0);
	
	lib.add_user(*p);
	cout << "Library properties:\n";
	lib.print_users();
	cout << endl;
	p->borrow_book(lib, book);

	cout << "Books borrwed by " << p->get_name() << endl;
	p->show_books();

	
	cout << "END" << endl;
}
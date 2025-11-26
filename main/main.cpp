#include <iostream>
#include "date.hpp"
#include "book.hpp"
#include "person.hpp"
#include "lst_utils.hpp"

using namespace std;

int main()
{
	string name = "Harry Potter";
	int id = 1;
	Book book1(name, id);

	name = "Percy Jackson";
	id = 2;
	Book book2(name, id);

	name = "Lord of the Rings";
	id = 3;
	Book book3(name, id);
	
	name = "Microelectronics 8th Edition";
	id = 4;
	Book book4(name, id);

	// Person person("Harry", "harry@gmail.com", 654654);
	// person.print();
	// person.borrow(*book1);

	Lst<Book> head;
	head.add_back(book1);
	head.add_back(book2);
	head.add_front(book3);
	head.add_at(3, book4);
	head.print();


	head.set(2, book3);
	head.print();
	head.clear();
	head.print();
	cout << "END" << endl;
}
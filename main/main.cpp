#include <iostream>
#include "date.hpp"
#include "book.hpp"
#include "person.hpp"
#include "lst_utils.hpp"
using namespace std;


int main()
{
	string name = "Harry Potter";
	int id = 12346;
	Book *book1 = new Book(name, id);

	name = "Percy Jackson";
	id = 98765;
	Book *book2 = new Book(name, id);
	
	// Person person("Harry", "harry@gmail.com", 654654);
	// person.print();
	// person.borrow(*book1);

	Lst<Book> head;
	head.add_back(*book1);
	head.add_back(*book2);
	head.add_front(*book1);
	head.add_at(3, *book2);

	head.remove_back();
	head.remove_front();
	head.print();
}
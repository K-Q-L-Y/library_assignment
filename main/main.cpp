#include <iostream>
#include "date.hpp"
#include "library.hpp"
#include "student.hpp"

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

	Person *p = new Student("Harry", "harry@gmail.com", "S1234");
	Library lib;

	lib.add_book(book1);
	lib.add_user(*p);
	
	p->borrow_book(lib, book1);

	p->show_books();

	lib.print_books();
	
	cout << "END" << endl;
}
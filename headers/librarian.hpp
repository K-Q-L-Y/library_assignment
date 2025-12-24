#ifndef LIBRARIAN_HPP
#define LIBRARIAN_HPP

#include "person.hpp"

class Librarian : public Person {
public:
    Librarian(string name, string email, string id)
        : Person(name, email, id) {
        role = Role::Librarian;
    }

    void add_book(Library &lib, Book &book) override {
        lib.add_book(book);
    }

    void remove_book(Library &lib, Book &book) override {
        lib.remove_book(book);
    }

    Lst<Book> search_book(Library &lib, string query) override {
        return lib.search_book(query);
    }

    void print() override {
        cout << "Librarian\n";
        cout << *this << endl;
    }
};

#endif

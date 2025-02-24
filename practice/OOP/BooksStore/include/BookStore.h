#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <vector>
#include "Book.h"

using namespace std;

class BookStore
{
private:
    vector<Book> books;

public:
    void addBook(const Book &books);
    void sellBook(const string &title);
    void listBook() const;
};
#endif
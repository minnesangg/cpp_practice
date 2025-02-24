#include "BookStore.h"
#include <iostream>
using namespace std;

void BookStore::addBook(const Book &book)
{
    books.push_back(book);
}

void BookStore::sellBook(const string &title)
{
    for (Book &book : books)
    {
        if (book.getTitle() == title)
        {
            book.sellBook();
            return;
        }
    }
    cout << "Book " << title << " not founded." << endl;
}

void BookStore::listBook() const
{
    for (const Book &book : books)
    {
        book.printInfo();
    }
}
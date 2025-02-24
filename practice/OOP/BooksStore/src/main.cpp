#include <iostream>
#include "BookStore.h"

using namespace std;

int main()
{
    BookStore store;

    store.addBook(Book("Harry Potter", "Joane Rowling", 1000, 10));
    store.addBook(Book("Ring Master", "John Tolkin", 1500, 5));

    store.sellBook("Harry Potter");

    store.listBook();

    return 0;
}
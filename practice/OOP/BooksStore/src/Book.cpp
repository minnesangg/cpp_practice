#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string author, string title, float price, int quantity)
    : author(author), title(title), price(price), quantity(quantity) {}

void Book::addStock(int amount)
{
    quantity += amount;
}

bool Book::sellBook()
{
    if (quantity > 0)
    {
        quantity--;
        return true;
    }
    else
    {
        cout << "Book " << title << " is over!" << endl;
        return false;
    }
}

void Book::printInfo() const
{
    cout << "Title: " << title << ", author: " << author << ", price: " << price << ", quantity: " << quantity << endl;
}

string Book::getTitle()
{
    return title;
}

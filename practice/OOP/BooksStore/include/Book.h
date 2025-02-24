#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    std::string author;
    std::string title;
    float price;
    int quantity;

public:
    Book(std::string author, std::string title, float price, int quantity);

    void addStock(int amount);
    bool sellBook();
    void printInfo() const;
    std::string getTitle();
};

#endif

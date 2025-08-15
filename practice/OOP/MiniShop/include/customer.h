#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "product.h"
#include "shop.h"

class Customer{
private:
    std::string name;
    unsigned int balance;
    unsigned int age;

public:
    Customer();
    Customer(std::string name, unsigned int balance, unsigned int age);

    std::string getName() const;
    unsigned int getBalance() const;
    unsigned int getAge() const;

    void setName(const std::string& name);
    void setBalance(unsigned int balance);
    void setAge(unsigned int age);

    void purchaseProduct(Product& product, unsigned int quantity);
    bool checkBeforePurchase(const Product& product, unsigned int quantity) const;
};

#endif // CUSTOMER_H
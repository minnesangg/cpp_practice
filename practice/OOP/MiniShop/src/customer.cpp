#include "customer.h"

Customer::Customer() : name(""), balance(0), age(0) {}

Customer::Customer(std::string name, unsigned int balance, unsigned int age)
    : name(name), balance(balance), age(age) {}

std::string Customer::getName() const {
    return name;
}

unsigned int Customer::getBalance() const {
    return balance;
}

unsigned int Customer::getAge() const {
    return age;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setBalance(unsigned int balance) {
    this->balance = balance;
}

void Customer::setAge(unsigned int age) {
    this->age = age;
}

void Customer::purchaseProduct(Product& product, unsigned int quantity) {
    if(!checkBeforePurchase(product, quantity)) {
        return;
    }

    balance -= product.getPrice() * quantity;
    product.setQuantity(product.getQuantity() - quantity);
    std::cout << "Purchased " << quantity << " of " << product.getName() << ". Remaining balance: " 
              << balance << std::endl;
}

bool Customer::checkBeforePurchase(const Product& product, unsigned int quantity) const {
    if(product.getQuantity() < quantity) {
        std::cout << "Not enough stock for product: " << product.getName() << std::endl;
        return false;
    }

    if(balance < product.getPrice() * quantity) {
        std::cout << "Insufficient balance to purchase product: " << product.getName() << std::endl;
        return false;
    }

    if(product.getIsAdultOnly() && age < 18) {
        std::cout << "You must be at least 18 years old to purchase this product: " 
                  << product.getName() << std::endl;

        return false;
    }
    return true;
}


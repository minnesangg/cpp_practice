#include "product.h"

Product::Product() : name(""), price(0.0), quantity(0), isAdultOnly(false) {}

Product::Product(std::string name, double price, unsigned int quantity, bool isAdultOnly)
    : name(name), price(price), quantity(quantity), isAdultOnly(isAdultOnly) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

unsigned int Product::getQuantity() const {
    return quantity;
}

bool Product::getIsAdultOnly() const {
    return isAdultOnly;
}

void Product::setName(const std::string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(unsigned int quantity) {
    this->quantity = quantity;
}

void Product::setIsAdultOnly(bool isAdultOnly) {
    this->isAdultOnly = isAdultOnly;
}
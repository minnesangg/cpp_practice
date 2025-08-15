#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    unsigned int quantity;
    bool isAdultOnly;

public:
    Product();
    Product(std::string name, double price, unsigned int quantity, bool isAdultOnly);

    std::string getName() const;
    double getPrice() const;
    unsigned int getQuantity() const;
    bool getIsAdultOnly() const;

    void setName(const std::string& name);
    void setPrice(double price);
    void setQuantity(unsigned int quantity);
    void setIsAdultOnly(bool isAdultOnly);
};

#endif // PRODUCT_H

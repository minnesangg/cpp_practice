#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <iostream>
#include "product.h"

class Shop {
private:
    std::vector<Product> products;

public:
    Shop();
    Shop(const std::vector<Product>& products);

    std::vector<Product> getProducts() const;
    void setProducts(const std::vector<Product>& products);
    void clearProducts();

    void addProduct(const Product& product);
    void removeProduct(const std::string& productName);
    Product* findProduct(const std::string& productName);
    void listProducts() const;
};

#endif // SHOP_H

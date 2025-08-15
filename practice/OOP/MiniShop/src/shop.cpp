#include "shop.h"
#include <algorithm>

Shop::Shop() {
    products = std::vector<Product>();
}

Shop::Shop(const std::vector<Product>& products) : products(products) {}

std::vector<Product> Shop::getProducts() const {
    return products;
}

void Shop::setProducts(const std::vector<Product>& products) {
    this->products = products;
}

void Shop::clearProducts() {
    products.clear();
}

void Shop::addProduct(const Product& product) {
    products.push_back(product);
}

Product* Shop::findProduct(const std::string& productName) {
    for(auto& product : products) {
        if(product.getName() == productName){
            return &product;
        }
    }
    return nullptr;
}

void Shop::removeProduct(const std::string& productName) {
    auto it = std::remove_if(products.begin(), products.end(),
        [&productName](const Product& product) {
            return product.getName() == productName;
        });
    if(it != products.end()) {
        products.erase(it, products.end());
    } else {
        std::cout << "Product not found: " << productName << std::endl;
    }
}

void Shop::listProducts() const {
    for(const auto& product : products){
        std::cout << "Name: " << product.getName()
                  << ", Price: " << product.getPrice()
                  << ", Quantity: " << product.getQuantity()
                  << ", Adult Only: " << (product.getIsAdultOnly() ? "Yes" : "No") 
                  << std::endl;
    }
}
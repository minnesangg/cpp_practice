#include "customer.h"

void createShop(Shop& shop){
    shop.addProduct(Product("Laptop", 1000, 5, false));
    shop.addProduct(Product("Phone", 500, 10, false));
    shop.addProduct(Product("Alcohol", 200, 2, true));
}

void testPurchase(Customer& customer, Shop& shop, const std::string& productName, unsigned int quantity) {
    Product* product = shop.findProduct(productName);
    if (product) {
        customer.purchaseProduct(*product, quantity);
    } else {
        std::cout << "Product not found: " << productName << std::endl;
    }
}

int main(){
    Shop* shop = new Shop();
    createShop(*shop);

    Customer* customer1 = new Customer("Alice", 1500, 25);
    Customer* customer2 = new Customer("Bob", 100, 17);

    shop->listProducts();

    testPurchase(*customer1, *shop, "Laptop", 1);
    testPurchase(*customer1, *shop, "Alcohol", 1);
    testPurchase(*customer2, *shop, "Phone", 1);
    testPurchase(*customer2, *shop, "Alcohol", 1);

    shop->removeProduct("Phone");
    shop->listProducts();

    delete shop;
    delete customer1;
    delete customer2;
}
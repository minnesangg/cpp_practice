#ifndef ORDER_H
#define ORDER_H

using uint = unsigned int;

#include "mnsng_vector.h"
#include "menuItem.h"

class Order {
private:
    minnesang::Vector<MenuItem> items;
    uint total_price;

public:
    Order();
    Order(minnesang::Vector<MenuItem> items, uint total_price);
    ~Order();

    minnesang::Vector<MenuItem> get_items() const;
    uint get_total_price() const;

    void set_items(minnesang::Vector<MenuItem> items);
    void set_total_price(uint total_price);

    void add_item(MenuItem item);
    void calculate_total();
    void print_order() const;

};

#endif
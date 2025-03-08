#ifndef CAFE_H
#define CAFE_H

#include "mnsng_vector.h"
#include "menuItem.h"
#include "order.h"

class Cafe {
private:
    minnesang::Vector<MenuItem> menu;
    minnesang::Vector<Order> orders;

public:
    Cafe();
    Cafe(minnesang::Vector<MenuItem> menu, minnesang::Vector<Order> orders);
    ~Cafe();

    minnesang::Vector<MenuItem> get_menu() const;
    minnesang::Vector<Order> get_orders() const;
    void set_menu(minnesang::Vector<MenuItem> items);
    void set_orders(minnesang::Vector<Order> orders);

    void add_menu_item(MenuItem item);
    void create_order(Order order);
    void print_menu() const;
    void print_orders() const;
};

#endif
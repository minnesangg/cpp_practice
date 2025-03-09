#ifndef CAFE_H
#define CAFE_H

#include "mnsng_vector.h"
#include "menuItem.h"
#include "order.h"
#include "waiter.h"
#include "manager.h"
#include "cook.h"

class Cafe {
private:
    minnesang::Vector<MenuItem> menu;
    minnesang::Vector<Order> orders;
    minnesang::Vector<Waiter> waiters;
    minnesang::Vector<Cook> cooks;
    minnesang::Vector<Manager> managers;

public:
    Cafe();
    Cafe(minnesang::Vector<MenuItem> menu, minnesang::Vector<Order> orders, minnesang::Vector<Waiter> waiters, 
        minnesang::Vector<Cook> cooks, minnesang::Vector<Manager> managers);
    ~Cafe();

    minnesang::Vector<MenuItem> get_menu() const;
    minnesang::Vector<Order> get_orders() const;
    minnesang::Vector<Waiter> get_waiters() const;
    minnesang::Vector<Cook> get_cooks() const;
    minnesang::Vector<Manager> get_managers() const;

    void set_menu(minnesang::Vector<MenuItem> items);
    void set_orders(minnesang::Vector<Order> orders);
    void set_waiters(minnesang::Vector<Waiter> waiters);
    void set_cooks(minnesang::Vector<Cook> cooks);
    void set_managers(minnesang::Vector<Manager> managers);

    void add_menu_item(MenuItem item);
    void create_order(Order order);
    void print_menu() const;
    void print_orders() const;
};

#endif
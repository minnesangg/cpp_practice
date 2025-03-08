#include "cafe.h"

Cafe::Cafe() {
    this->menu = minnesang::Vector<MenuItem>();
    this->orders = minnesang::Vector<Order>();
}

Cafe::Cafe(minnesang::Vector<MenuItem> menu, minnesang::Vector<Order> orders) {
    this->menu = menu;
    this->orders = orders;
}

Cafe::~Cafe() {}

minnesang::Vector<MenuItem> Cafe::get_menu() const{
    return menu;
}

minnesang::Vector<Order> Cafe::get_orders() const{
    return orders;
}

void Cafe::set_menu(minnesang::Vector<MenuItem> menu){
    this->menu = menu;
}

void Cafe::set_orders(minnesang::Vector<Order> orders){
    this->orders = orders;
}

void Cafe::add_menu_item(MenuItem item){
    menu.push_back(item);
}

void Cafe::create_order(Order order){
    orders.push_back(order);
}

void Cafe::print_menu() const {
    std::cout << "Menu: " << std::endl;
    for (size_t i = 0; i < menu.get_size(); i++) {
        menu[i].print_item(); 
    }
}

void Cafe::print_orders() const {
    std::cout << "Orders: " << std::endl;
    for (size_t i = 0; i < orders.get_size(); i++) {
        orders[i].print_order(); 
    }
}

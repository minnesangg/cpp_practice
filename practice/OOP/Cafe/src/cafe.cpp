#include "cafe.h"

Cafe::Cafe() {
    this->menu = minnesang::Vector<MenuItem>();
    this->orders = minnesang::Vector<Order>();
    this->waiters = minnesang::Vector<Waiter>();
    this->cooks = minnesang::Vector<Cook>();
    this->managers = minnesang::Vector<Manager>();
}

Cafe::Cafe(minnesang::Vector<MenuItem> menu, minnesang::Vector<Order> orders, minnesang::Vector<Waiter> waiters, 
    minnesang::Vector<Cook> cooks, minnesang::Vector<Manager> managers) {
    this->menu = menu;
    this->orders = orders;
    this->waiters = waiters;
    this->cooks = cooks;
    this->managers = managers;
}

Cafe::~Cafe() {}

minnesang::Vector<MenuItem> Cafe::get_menu() const{
    return menu;
}

minnesang::Vector<Order> Cafe::get_orders() const{
    return orders;
}

minnesang::Vector<Waiter> Cafe::get_waiters() const{
    return waiters;
}

minnesang::Vector<Cook> Cafe::get_cooks() const{
    return cooks;
}

minnesang::Vector<Manager> Cafe::get_managers() const{
    return managers;
}

void Cafe::set_menu(minnesang::Vector<MenuItem> menu){
    this->menu = menu;
}

void Cafe::set_orders(minnesang::Vector<Order> orders){
    this->orders = orders;
}

void Cafe::set_waiters(minnesang::Vector<Waiter> waiters){
    this->waiters = waiters;
}

void Cafe::set_cooks(minnesang::Vector<Cook> cooks){
    this->cooks = cooks;
}

void Cafe::set_managers(minnesang::Vector<Manager> managers){
    this->managers = managers;
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

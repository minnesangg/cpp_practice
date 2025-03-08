#include "order.h"

Order::Order() {
    this->total_price = 0;
}

Order::Order(minnesang::Vector<MenuItem> items, uint total_price) {
    this->items = items;
    this->total_price = total_price;
}

Order::~Order() {}

minnesang::Vector<MenuItem> Order::get_items() const{
    return items;
}

uint Order::get_total_price() const{
    return total_price;
}

void Order::set_items(minnesang::Vector<MenuItem> items){
    this->items = items;
}

void Order::set_total_price(uint total_price){
    this->total_price = total_price;
}

void Order::add_item(MenuItem item){
    items.push_back(item);
}

void Order::calculate_total(){
    total_price = 0;
    for(size_t i = 0; i < items.get_size(); i++){
        total_price += items[i].get_price();
    }
    std::cout << "Total price: " << total_price << std::endl;
}

void Order::print_order() const{
    for(size_t i = 0; i < items.get_size(); i++){
        items[i].print_item();
    }
}
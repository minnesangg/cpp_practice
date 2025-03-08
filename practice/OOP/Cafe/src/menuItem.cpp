#include "menuItem.h"

MenuItem::MenuItem() {
    this->name = "NoNe";
    this->price = 0;
}

MenuItem::MenuItem(std::string name, uint price) {
    this->name = name;
    this->price = price;
}

MenuItem::~MenuItem(){}

std::string MenuItem::get_name() const{
    return name;
}

uint MenuItem::get_price() const{
    return price;
}

void MenuItem::set_name(std::string name) {
    this->name = name;
}

void MenuItem::set_price(uint price){
    this->price = price;
}

void MenuItem::print_item() const{
    std::cout <<  name << " " << price << std::endl;
}
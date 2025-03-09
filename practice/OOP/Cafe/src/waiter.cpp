#include "waiter.h"

Waiter::Waiter() {
    this->name = "NoName";
    this->age = 0;
    this->salary = 0;
    this->hours_per_week = 0;

    this->tips = 0;
}

Waiter::Waiter(std::string name, uint age, uint salary, uint hours_per_week){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;

    this->tips = 0;
}

Waiter::Waiter(std::string name, uint age, uint salary, uint hours_per_week, uint tips){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;

    this->tips = tips;
}

Waiter::~Waiter() {}

uint Waiter::get_tips() const{
    return tips;
}

void Waiter::set_tips(uint tips){
    this->tips = tips;
}

void Waiter::add_tip(uint new_tip){
    tips += new_tip;
}

void Waiter::print_info() const{
    std::cout << "Waiter: ";
    std::cout << "name - " << name << ", age - " << age << ", salary - " << salary << ", hours per week - " << hours_per_week 
    << ", tips " << tips << std::endl;
}

void Waiter::bonus(uint bonus){
    salary += bonus;
    std::cout << "Waiter received bonus: " << bonus << std::endl;
}
#include "employee.h"

Employee::Employee() {
    this->name = "NoName";
    this->age = 0;
    this->salary = 0;
    this->hours_per_week = 0;
}

Employee::Employee(std::string name, uint age, uint salary, uint hours_per_week) {
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;
}

Employee::~Employee(){}

std::string Employee::get_name() const{
    return name;
}

uint Employee::get_age() const{
    return age;
}

uint Employee::get_salary() const{
    return salary;
}

uint Employee::get_hours_per_week() const{
    return hours_per_week;
}

void Employee::set_name(std::string name){
    this->name = name;
}

void Employee::set_age(uint age){
    this->age = age;
}

void Employee::set_salary(uint salary){
    this->salary = salary;
}

void Employee::set_hours_per_week(uint hours_per_week){
    this->hours_per_week = hours_per_week;
}

void Employee::print_info() const{
    std::cout << "Employee: ";
    std::cout << "name - " << name << ", age - " << age << ", salary - " << salary << ", hours per week - " << hours_per_week 
    << std::endl;
}

void Employee::bonus(uint bonus) {
    salary += bonus;
}

void Employee::change_hours_per_week(){
    std::string result;
    std::cout << "Add or substract hours per week(+, -)?" << std::endl;
    std::cin >> result;

    uint hours;
    std::cout << "How many hours you want to add/substract?" << std::endl;
    std::cin >> hours;
    bool changing = false;
    if(result == "+")
        changing = true;

    changing ? hours_per_week += hours : hours_per_week -= hours;
}

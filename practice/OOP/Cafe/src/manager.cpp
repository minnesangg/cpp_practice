#include "manager.h"

Manager::Manager(){
    this->name = "NoName";
    this->age = 0;
    this->salary = 0;
    this->hours_per_week = 0;

    this->team_size = 0;
}

Manager::Manager(std::string name, uint age, uint salary, uint hours_per_week){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;
    
    this->team_size = 0;
}

Manager::Manager(std::string name, uint age, uint salary, uint hours_per_week, uint team_size){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;

    this->team_size = team_size;
}

Manager::~Manager() {}

uint Manager::get_team_size() const{
    return team_size;
}

void Manager::set_team_size(uint team_size){
    this->team_size = team_size;
}

void Manager::print_info() const{
    std::cout << "Manager: ";
    std::cout << "name - " << name << ", age - " << age << ", salary - " << salary << ", hours per week - " << hours_per_week 
    << ", team size -  " << team_size << std::endl;
}

void Manager::bonus(uint bonus){
    salary += bonus;
    std::cout << "Manager received bonus: " << bonus << std::endl;
}


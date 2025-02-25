#include "manager.h"

Manager::Manager(){
    name = "No name";
    age = 0;
    salary = 0;
    team_size = 0;
}

Manager::Manager(std::string name, int age, int salary){
    this->name = name;
    this->age = age;
    this->salary = salary;
    team_size = 0;
}

Manager::Manager(std::string name, int age, int salary, int team_size){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->team_size = team_size;
}

void Manager::set_team_size(int team_size){
    this->team_size = team_size;
}

int Manager::get_team_size() const{
    return team_size;
}

void Manager::print_info(const Employee& employee) const{
    Employee::print_info(employee);
    std::cout << "Team size: " << team_size << std::endl;
}
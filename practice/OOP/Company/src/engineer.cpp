#include "engineer.h"

Engineer::Engineer(){
    name = "No name";
    age = 0;
    salary = 0;
    projects_count = 0;
}

Engineer::Engineer(std::string name, int age, int salary){
    this->name = name;
    this->age = age;
    this->salary = salary;
    projects_count = 0;
}

Engineer::Engineer(std::string name, int age, int salary, int projects_count){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->projects_count = projects_count;
}

void Engineer::set_projects_count(int projects_count){
    this->projects_count = projects_count;
}

int Engineer::get_projects_count() const{
    return projects_count;
}

void Engineer::print_info(const Employee& employee) const{
    Employee::print_info(employee);
    std::cout << "Projects count: " << projects_count << std::endl;   
}
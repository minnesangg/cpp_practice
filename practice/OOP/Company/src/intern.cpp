#include "intern.h"

Intern::Intern(){
    name = "No name";
    age = 0;
    salary = 0;
    mentor_name = "No mentor";
}

Intern::Intern(std::string name, int age, int salary){
    this->name = name;
    this->age = age;
    this->salary = salary;
    mentor_name = "No mentor";
}

Intern::Intern(std::string name, int age, int salary, std::string mentor_name){
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->mentor_name = mentor_name;
}

std::string Intern::get_mentor_name() const{
    return mentor_name;
}

void Intern::set_mentor_name(std::string mentor_name){
    this->mentor_name = mentor_name;
}

void Intern::print_info(const Employee& employee) const {
    Employee::print_info(employee); 
    std::cout << "Mentor: " << mentor_name << std::endl;
}

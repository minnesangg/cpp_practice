#include"employee.h"

Employee::Employee(){
    name = "No name";
    age = 0;
    salary = 0;
}

Employee::Employee(std::string name, int age, int salary){
    this->name = name;
    this->age = age;
    this->salary = salary;
}

Employee::~Employee(){
    std::cout << "Employee " << name << " is deleted" << std::endl;
}

void Employee::set_name(std::string name){
    this->name = name;
}

std::string Employee::get_name() const{
    return name;
}

void Employee::set_age(int age){
    this->age = age;
}

int Employee::get_age() const{
    return age;
}

void Employee::set_salary(int salary){
    this->salary = salary;
}

int Employee::get_salary() const{
    return salary;
}

void Employee::print_info(const Employee& employee) const{
    std::cout << "Name: " << employee.get_name() << std::endl;
    std::cout << "Age: " << employee.get_age() << std::endl;
    std::cout << "Salary: " << employee.get_salary() << std::endl;
}

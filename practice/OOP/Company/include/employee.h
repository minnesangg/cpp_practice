#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee{
protected:
    std::string name;
    int age;
    int salary;
public:
    Employee();
    Employee(std::string name, int age, int salary);
    ~Employee() {};
    void set_name(std::string name);
    void set_age(int age);
    void set_salary(int salary);

    std::string get_name() const;
    int get_age() const;
    int get_salary() const;

    virtual void print_info(const Employee& employee) const;
};

#endif
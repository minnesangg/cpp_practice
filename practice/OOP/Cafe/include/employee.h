#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using uint = unsigned int;

class Employee {
protected:
    std::string name;
    uint age;
    uint salary;
    uint hours_per_week;

public:
    Employee();
    Employee(std::string name, uint age, uint salary, uint hours_per_week);
    virtual ~Employee();

    std::string get_name() const;
    uint get_age() const;
    uint get_salary() const;
    uint get_hours_per_week() const;

    void set_name(std::string name);
    void set_age(uint age);
    void set_salary(uint salary);
    void set_hours_per_week(uint hours_per_week);

    virtual void print_info() const;
    virtual void bonus(uint bonus);
    void change_hours_per_week();
};

#endif
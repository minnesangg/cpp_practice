#ifndef INTERN_H
#define INTERN_H

#include "employee.h"

class Intern : public Employee{
private:
    std::string mentor_name;
public:
    Intern();
    Intern(std::string name, int age, int salary);
    Intern(std::string name, int age, int salary, std::string mentor_name);
    ~Intern();

    std::string get_mentor_name() const;
    void set_mentor_name(std::string mentor_name);

    void print_info(const Employee& employee) const override;
};

#endif
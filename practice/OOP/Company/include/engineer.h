#ifndef ENGINEER_H
#define ENGINEER_H

#include "employee.h"

class Engineer : public Employee{
private:
    int projects_count;
public:
    Engineer();
    Engineer(std::string name, int age, int salary);
    Engineer(std::string name, int age, int salary, int projects_count);
    ~Engineer();

    void set_projects_count(int projects_count);
    int get_projects_count() const;

    void print_info(const Employee& employee) const override;

}; 

#endif
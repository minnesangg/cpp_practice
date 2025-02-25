#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee{
private:
    int team_size;
public:
    Manager();
    Manager(std::string name, int age, int salary);
    Manager(std::string name, int age, int salary, int team_size);
    ~Manager();

    void set_team_size(int team_size);
    int get_team_size() const;

    void print_info(const Employee& employee) const override;    

};

#endif
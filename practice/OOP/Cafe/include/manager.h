#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee {
private:
    uint team_size;
public:
    Manager();
    Manager(std::string name, uint age, uint salary, uint hours_per_week);
    Manager(std::string name, uint age, uint salary, uint hours_per_week, uint team_size);
    ~Manager();

    uint get_team_size() const;
    void set_team_size(uint team_size);

    void print_info() const override;
    void bonus(uint bonus) override;
};

#endif
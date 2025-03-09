#ifndef WAITER_H
#define WAITER_H

#include "employee.h"

class Waiter : public Employee {
private:
    uint tips;

public:
    Waiter();
    Waiter(std::string name, uint age, uint salary, uint hours_per_week);
    Waiter(std::string name, uint age, uint salary, uint hours_per_week, uint tips);
    ~Waiter();

    uint get_tips() const;

    void set_tips(uint tips);

    void add_tip(uint new_tip);
    void print_info() const override;
    void bonus(uint bonus) override;
};  

#endif
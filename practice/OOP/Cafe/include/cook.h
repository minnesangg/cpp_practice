#ifndef COOK_H
#define COOK_H

#include "employee.h"

class Cook : public Employee {
public:  
    enum class Skill {
        Junior,
        Middle,
        Sous_Chief,
        Chief
    };

private:
    Skill cook_skill;

public:
    Cook();
    Cook(std::string name, uint age, uint salary, uint hours_per_week);
    Cook(std::string name, uint age, uint salary, uint hours_per_week, Skill cook_skill);
    ~Cook();

    Skill get_cook_skill() const;
    void set_cook_skill(Skill cook_skill);

    void print_info() const override;
    void bonus(uint bonus) override;
};

#endif

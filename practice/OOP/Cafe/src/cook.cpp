#include "cook.h"

Cook::Cook() {
    this->name = "NoName";
    this->age = 0;
    this->salary = 0;
    this->hours_per_week = 0;
    this->cook_skill = Skill::Junior;
}

Cook::Cook(std::string name, uint age, uint salary, uint hours_per_week) {
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;
    this->cook_skill = Skill::Junior;
}

Cook::Cook(std::string name, uint age, uint salary, uint hours_per_week, Skill cook_skill) {
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->hours_per_week = hours_per_week;
    this->cook_skill = cook_skill;
}

Cook::~Cook() {}

Cook::Skill Cook::get_cook_skill() const {
    return cook_skill;
}

void Cook::set_cook_skill(Skill cook_skill) {
    this->cook_skill = cook_skill;
}

void Cook::print_info() const {
    std::string str_skill;
    switch (cook_skill) {
        case Skill::Junior:
            str_skill = "junior";
            break;
        case Skill::Middle:
            str_skill = "middle";
            break;
        case Skill::Sous_Chief:
            str_skill = "sous-chief";
            break;
        case Skill::Chief:
            str_skill = "chief";
            break;
    }

    std::cout << "Cook: ";
    std::cout << "name - " << name << ", age - " << age << ", salary - " << salary;

    if constexpr (std::is_base_of<Employee, Cook>::value) {
        std::cout << ", hours per week - " << this->hours_per_week;
    }
    
    std::cout << ", cook's skill - " << str_skill << std::endl;
}

void Cook::bonus(uint bonus) {
    salary += bonus;
    std::cout << "Cook received bonus: " << bonus << std::endl;
}

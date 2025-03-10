#ifndef FARMENTITY_H
#define FARMENTITY_H

#include <string>
#include <iostream>

using uint = unsigned int;

class FarmEntity{
protected:
    std::string name;
    float health;
    bool is_alive;

public:
    FarmEntity();
    FarmEntity(std::string name, float health, bool is_alive);
    virtual ~FarmEntity();

    std::string get_name() const;
    float get_health() const;
    bool get_alive_status() const;

    void set_name(std::string name);
    void set_health(float health);
    void set_alive_status(bool is_alive);

    virtual void show_info() const = 0;
    void take_damage(float amount);
    void heal(float amount);
    bool check_status();

};

#endif
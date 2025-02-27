#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
protected:
    float speed;
    float fuel;
    std::string name;

public:
    Vehicle();
    Vehicle(std::string name, float speed, float fuel);
    virtual ~Vehicle();

    float get_speed() const;
    float get_fuel() const;
    std::string get_name() const;

    void set_speed(float speed);
    void set_fuel(float fuel);
    void set_name(std::string name);

    void refuel(float amount);

    virtual void move();
    virtual void display_info();
};

#endif
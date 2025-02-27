#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class Motorcycle : public Vehicle {
private:
    bool side_car;

public:
    Motorcycle();
    Motorcycle(std::string name, float speed, float fuel);
    Motorcycle(std::string name, float speed, float fuel, bool side_car);
    ~Motorcycle();

    double get_side_car() const;
    bool set_side_car(bool side_car);
    void display_info() override;
    void move() override;
};

#endif
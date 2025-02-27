#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle{
private:
    double cargo_weight;

public:
    Truck();
    Truck(std::string name, float speed, float fuel);
    Truck(std::string name, float spped, float fuel, double cargo_weight);
    ~Truck();

    double get_cargo_weight() const;
    void set_cargo_weight(double cargo_weight);

    void display_info() override;
    void move() override;
};

#endif
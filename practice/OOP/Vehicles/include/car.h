#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle{
private:
    unsigned int passengers;

public:
    Car();
    Car(std::string name, float speed, float fuel);
    Car(std::string name, float speed, float fuel, unsigned int passengers);
    ~Car();

    unsigned int get_passengers() const;
    void set_passengers(unsigned int passengers);
    void display_info() override;
    void move() override;
};

#endif
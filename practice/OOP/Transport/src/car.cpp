#include "car.h"

Car::Car(int max_speed) : Transport(max_speed) {}

void Car::move() const {
    std::cout << "Car is moving" << std::endl;
}

void Car::print_max_speed() const {
    std::cout << "Max speed of the car is " << get_max_speed() << std::endl;
}


#include "bicycle.h"

Bicycle::Bicycle(int max_speed) : Transport(max_speed) {}

void Bicycle::move() const {
    std::cout << "Bicycle is moving" << std::endl;
}

void Bicycle::print_max_speed() const {
    std::cout << "Max speed of the bicycle is " << get_max_speed() << std::endl;
}
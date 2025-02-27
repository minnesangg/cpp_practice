#include "vehicle.h"

Vehicle::Vehicle() : speed(0), fuel(0), name("unnamed") {}

Vehicle::Vehicle(std::string name, float speed, float fuel){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
}

Vehicle::~Vehicle() {}

float Vehicle::get_speed() const{
    return speed;
}

float Vehicle::get_fuel() const{
    return fuel;
}

std::string Vehicle::get_name() const{
    return name;
}

void Vehicle::set_speed(float speed){
    this->speed = speed;
}

void Vehicle::set_fuel(float fuel){
    this->fuel = fuel;
}

void Vehicle::set_name(std::string name){
    this->name = name;
}

void Vehicle::refuel(float amount){
    this->fuel += amount;
    std::cout << "Vehicle has been refueled" << std::endl;
}

void Vehicle::move(){
    if(fuel > 0){
        fuel -= 1;
        std::cout << "Vehicle is moving at " << speed << " km/h" << std::endl;
    } else {
        std::cout << "Vehicle has no fuel" << std::endl;
    }
}

void Vehicle::display_info(){
    std::cout << "Vehicle: " << name << std::endl;
    std::cout << "Speed: " << speed << " km/h" << std::endl;
    std::cout << "Fuel: " << fuel << " liters" << std::endl;
}
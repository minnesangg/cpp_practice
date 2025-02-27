#include "car.h"

using uint = unsigned int;

Car::Car(){
    this->name = "unnamed";
    this->speed = 0;
    this->fuel = 0;
    this->passengers = 0;
}

Car::Car(std::string name, float speed, float fuel){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->passengers = 0;
}

Car::Car(std::string name, float speed, float fuel, uint passengers) {
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->passengers = passengers;
}

Car::~Car() {}

uint Car::get_passengers() const{
    return passengers;
}

void Car::set_passengers(uint passengers){
    this->passengers = passengers;
}

void Car::display_info(){
    std::cout << "Car: " << name << std::endl;
    std::cout << "Speed: " << speed << " km/h" << std::endl;
    std::cout << "Fuel: " << fuel << " liters" << std::endl;
    std::cout << "Passengers: " << passengers << std::endl;
}

void Car::move(){
    if(fuel > 0){
        fuel -= 1;
        std::cout << "Car is moving at " << speed << " km/h" << std::endl;
    } else {
        std::cout << "Car has no fuel" << std::endl;
    }
}
#include "motorcycle.h"

Motorcycle::Motorcycle(){
    this->name = "unnamed";
    this->speed = 0;
    this->fuel = 0;
    this->side_car = 0;
}

Motorcycle::Motorcycle(std::string name, float speed, float fuel){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->side_car = 0;
}

Motorcycle::Motorcycle(std::string name, float speed, float fuel, bool side_car){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->side_car = side_car;
}

Motorcycle::~Motorcycle() {}

double Motorcycle::get_side_car() const{
    return side_car;
}

bool Motorcycle::set_side_car(bool side_car){
    this->side_car = side_car;
}

void Motorcycle::display_info(){
    std::cout << "Motorcycle: " << name << std::endl;
    std::cout << "Speed: " << speed << " km/h" << std::endl;
    std::cout << "Fuel: " << fuel << " liters" << std::endl;
    std::cout << "Side car status: " << side_car << std::endl;
}

void Motorcycle::move(){
    if(fuel > 0){
        fuel -= 1;
        std::cout << "Motorcycle is moving at " << speed << " km/h" << std::endl;
    } else {
        std::cout << "Motorcycle has no fuel" << std::endl;
    }
}
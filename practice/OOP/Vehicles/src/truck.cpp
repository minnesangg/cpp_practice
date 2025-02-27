#include "truck.h"

Truck::Truck(){
    this->name = "unnamed";
    this->speed = 0;
    this->fuel = 0;
    this->cargo_weight = 0;
}

Truck::Truck(std::string name, float speed, float fuel){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->cargo_weight = 0;
}

Truck::Truck(std::string name, float speed, float fuel, double cargo_weight){
    this->name = name;
    this->speed = speed;
    this->fuel = fuel;
    this->cargo_weight = cargo_weight;
}

Truck::~Truck() {}

double Truck::get_cargo_weight() const{
    return cargo_weight;
}

void Truck::set_cargo_weight(double cargo_weight){
    this->cargo_weight = cargo_weight;
}

void Truck::display_info(){
    std::cout << "Truck: " << name << std::endl;
    std::cout << "Speed: " << speed << " km/h" << std::endl;
    std::cout << "Fuel: " << fuel << " liters" << std::endl;
    std::cout << "Cargo weight: " << cargo_weight << " tons" << std::endl;
}

void Truck::move(){
    if(fuel > 0){
        fuel -= 1;
        std::cout << "Truck is moving at " << speed << " km/h" << std::endl;
    } else {
        std::cout << "Truck has no fuel" << std::endl;
    }
}
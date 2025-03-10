#include "animal.h"

Animal::Animal() {
    this->name = "NoName";
    this->health = 0.0;
    this->is_alive = false;

    this->sound = "NoSound";
    this->food_consumption = 0.0;
    this->productivity = 0.0;
}

Animal::Animal(std::string name, float health, bool is_alive){
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->sound = "NoSound";
    this->food_consumption = 0.0;
    this->productivity = 0.0;
}

Animal::Animal(std::string name, float health, bool is_alive, std::string sound, float food_consumption, float productivity){
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->sound = sound;
    this->food_consumption = food_consumption;
    this->productivity = productivity;
}

Animal::~Animal() {}

std::string Animal::get_sound() const{
    return sound;
}

float Animal::get_food_consumption() const{
    return food_consumption;
}

float Animal::get_productivity() const{
    return productivity;
}

void Animal::set_sound(std::string sound){
    this->sound = sound;
}

void Animal::set_food_consumption(float food_consumption){
    this->food_consumption = food_consumption;
}

void Animal::set_productivity(float productivity){
    this->productivity = productivity;
}

void Animal::make_sound() const{
    std::cout << "Animal's sound" << std::endl;
}

float Animal::produce_resources() const {
    float result = get_productivity();
    return result;
}

void Animal::feed(float food_amount){
    food_consumption -= food_amount;
}

void Animal::show_info() const{
    std::cout << "Info about animal: ";
    std::cout << "Name - " << name << ", health - " << health << ", is alive - " << is_alive << ", sound - " << sound 
    << ", food consumption - " << food_consumption << ", productivity - " << productivity << std::endl;
}
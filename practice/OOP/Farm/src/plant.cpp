#include "plant.h"

Plant::Plant() {
    this->name = "NoName";
    this->health = 0.0;
    this->is_alive = false;

    this->growth_time = 0;
    this->water_need = 0.0;
    this->yield = 0.0;
}

Plant::Plant(std::string name, float health, bool is_alive) {
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->growth_time = 0;
    this->water_need = 0.0;
    this->yield = 0.0;
}

Plant::Plant(std::string name, float health, bool is_alive, int growth_time, float water_need, float yield) {
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->growth_time = growth_time;
    this->water_need = water_need;
    this->yield = yield;
}

Plant::~Plant() {}

uint Plant::get_growth_time() const{
    return growth_time;
}

float Plant::get_water_need() const{
    return water_need;
}

float Plant::get_yield() const{
    return yield;
}

void Plant::set_growth_time(int growth_time){
    this->growth_time = growth_time;
}

void Plant::set_water_need(float water_need){
    this->water_need = water_need;
}

void Plant::set_yield(float yield){
    this->yield = yield;
}

void Plant::water(float amount){
    water_need -= amount;
}

bool Plant::is_ready_to_harvest() const{
    if (growth_time <= 0)
        return true;
    return false;
}

float Plant::harvest(){
    return yield;
}

void Plant::show_info() const{
    std::cout << "Info about plant: ";
    std::cout << "Name - " << name << ", health - " << health << ", is alive - " << is_alive << ", growth time - " << growth_time 
    << ", water need - " << water_need << ", yield - " << yield << std::endl;
}
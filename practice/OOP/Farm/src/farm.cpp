#include "farm.h"

Farm::Farm() {
    this->name = "NoName";
    this->health = 0.0;
    this->is_alive = false;

    this->entities = minnesang::Vector<FarmEntity*>();
    this->total_food_stock = 0;
    this->total_water_stock = 0;
}

Farm::Farm(std::string name, float health, bool is_alive) {
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->entities = minnesang::Vector<FarmEntity*>();
    this->total_food_stock = 0;
    this->total_water_stock = 0;
}

Farm::Farm(std::string name, float health, bool is_alive, minnesang::Vector<FarmEntity*> entities, 
                                                        float total_food_stock, float total_water_stock) {
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;

    this->entities = entities;
    this->total_food_stock = total_food_stock;
    this->total_water_stock = total_water_stock;
}

Farm::~Farm() {}

minnesang::Vector<FarmEntity*> Farm::get_entities() const{
    return entities;
}

float Farm::get_total_food_stock() const{
    return total_food_stock;
}

float Farm::get_total_water_stock() const{
    return total_water_stock;
}

void Farm::set_entities(minnesang::Vector<FarmEntity*> entities) {
    this->entities = entities;
}

void Farm::set_total_food_stock(float total_food_stock){
    this->total_food_stock = total_food_stock;
}

void Farm::set_total_water_stock(float total_water_stock){
    this->total_water_stock = total_water_stock;
}

void Farm::add_entity(FarmEntity* entity){
    entities.push_back(entity);
}

void Farm::feed_animals(float food){
    total_food_stock -= food;
}

void Farm::water_plants(float water){
    total_water_stock -= water;
}

void Farm::show_info() const {
    for (const auto& entity : entities) {
        entity->show_info();  
    }
}

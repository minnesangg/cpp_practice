#include "farmEntity.h"

FarmEntity::FarmEntity() {
    this->name = "NoName";
    this->health = 0.0;
    this->is_alive = false;
}

FarmEntity::FarmEntity(std::string name, float health, bool is_alive){
    this->name = name;
    this->health = health;
    this->is_alive = is_alive;
}

FarmEntity::~FarmEntity() {}

std::string FarmEntity::get_name() const{
    return name;
}

float FarmEntity::get_health() const{
    return health;
}

bool FarmEntity::get_alive_status() const{
    return is_alive;
}

void FarmEntity::set_name(std::string name){
    this->name = name;
}

void FarmEntity::set_health(float health){
    this->health = health;
}

void FarmEntity::set_alive_status(bool is_alive){
    this->is_alive = is_alive;
}

void FarmEntity::take_damage(float amount){
    if(health > 0)
        health -= amount;
    check_status();
}

void FarmEntity::heal(float amount){
    health += amount;
}

bool FarmEntity::check_status(){
    if(health <= 0)
        is_alive = false;
    return is_alive;
}
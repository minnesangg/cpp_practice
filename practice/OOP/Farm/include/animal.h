#ifndef ANIMAL_H
#define ANIMAL_H

#include "farmEntity.h"

class Animal : public FarmEntity {
private:
    std::string sound;
    float food_consumption;
    float productivity;
    
public:
    Animal();
    Animal(std::string name, float health, bool is_alive);
    Animal(std::string name, float health, bool is_alive, std::string sound, float food_consumption, float productivity);
    ~Animal();

    std::string get_sound() const;
    float get_food_consumption() const;
    float get_productivity() const;

    void set_sound(std::string sound);
    void set_food_consumption(float food_consumption);
    void set_productivity(float productivity);

    void make_sound() const;
    float produce_resources() const;
    void feed(float food_amount);
    void show_info() const override;
};

#endif
#ifndef PLANT_H
#define PLANT_H

#include "farmEntity.h"

class Plant : public FarmEntity {
private:
    int growth_time;
    float water_need;
    float yield;

public:
    Plant();
    Plant(std::string name, float health, bool is_alive);
    Plant(std::string name, float health, bool is_alive, int growth_time, float water_need, float yield);
    ~Plant();

    uint get_growth_time() const;
    float get_water_need() const;
    float get_yield() const;

    void set_growth_time(int growth_time);
    void set_water_need(float water_need);
    void set_yield(float yield);

    void water(float amount);
    bool is_ready_to_harvest() const;
    float harvest();
    void show_info() const override;
}; 

#endif
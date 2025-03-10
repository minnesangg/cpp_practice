#ifndef FARM_H
#define FARM_H

#include "mnsng_vector.h"
#include "farmEntity.h"

class Farm : public FarmEntity {
private:
    minnesang::Vector<FarmEntity*> entities;
    float total_food_stock;
    float total_water_stock;

public:
    Farm();
    Farm(std::string name, float health, bool is_alive);
    Farm(std::string name, float health, bool is_alive, minnesang::Vector<FarmEntity*> entities, 
        float total_food_stock, float total_water_stock);
    ~Farm();

    minnesang::Vector<FarmEntity*> get_entities() const;
    float get_total_food_stock() const;
    float get_total_water_stock() const;

    void set_entities(minnesang::Vector<FarmEntity*> entities);
    void set_total_food_stock(float total_food_stock);
    void set_total_water_stock(float total_water_stock);

    void add_entity(FarmEntity* entity);
    void feed_animals(float food);
    void water_plants(float water);
    void show_info() const override;
};

#endif
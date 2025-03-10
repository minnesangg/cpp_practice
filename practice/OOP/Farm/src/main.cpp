#include "farm.h"
#include "animal.h"
#include "plant.h"

int main(){
    Farm my_farm;

    my_farm.add_entity(new Animal("Cow", 100.0f, true, "Moo-Moo", 10.5f, 5.0f));
    my_farm.add_entity(new Animal("Chicken", 50.0f, true, "Co-Co", 1.2f, 0.8f));
    my_farm.add_entity(new Plant("Corn", 100.0f, true, 120, 5.0f, 20.0f));
    
    my_farm.show_info();
    my_farm.feed_animals(2);
    my_farm.water_plants(1);
}

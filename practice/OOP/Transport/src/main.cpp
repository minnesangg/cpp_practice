#include "car.h"
#include "bicycle.h"

int main(){
    Transport* vehicles[] = {new Car(100), new Bicycle(20)};

    for(Transport* vehicle : vehicles){
        vehicle->move();
        vehicle->print_max_speed();
    }

    for(Transport* vehicle : vehicles){
        delete vehicle;
    }

    return 0;
}
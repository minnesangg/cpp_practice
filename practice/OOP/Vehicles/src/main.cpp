#include "car.h"
#include "truck.h"
#include "motorcycle.h"

#include <memory>
#include <iostream>
#include <vector>

int main(){
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.push_back(std::make_unique<Car>("Toyota", 120, 50, 5));
    vehicles.push_back(std::make_unique<Truck>("Volvo", 80, 70, 2000));
    vehicles.push_back(std::make_unique<Motorcycle>("Harley", 150, 20, false));

    for (auto& v : vehicles) {
        v->display_info();
        v->move();
        std::cout << "-------------------\n";
    }

    return 0;
}
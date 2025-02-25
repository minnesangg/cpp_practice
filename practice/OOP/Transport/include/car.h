#ifndef CAR_H
#define CAR_H

#include "transport.h"

class Car : public Transport {
public:
    Car(int max_speed);
    void move() const override;
    void print_max_speed() const override;
};

#endif 
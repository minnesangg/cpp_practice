#ifndef BICYCLE_H
#define BICYCLE_H

#include "transport.h"

class Bicycle : public Transport {
public:
    Bicycle(int max_speed);
    void move() const override;
    void print_max_speed() const override;
};    

#endif
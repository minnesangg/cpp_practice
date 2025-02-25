#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>

class Transport {
private:
    int max_speed;
public:
    Transport(int max_speed);
    int get_max_speed() const;
    virtual void move() const;
    virtual void print_max_speed() const;
    virtual ~Transport() {}
};

#endif  
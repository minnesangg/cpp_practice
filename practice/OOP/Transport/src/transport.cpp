#include "transport.h"

Transport::Transport(int max_speed) : max_speed(max_speed) {}

void Transport::move() const{
    std::cout << "Transport is moving" << std::endl;
}

int Transport::get_max_speed() const {
    return max_speed;
}

void Transport::print_max_speed() const{
    std::cout << "Max speed of the transport is " << get_max_speed() << std::endl;
}
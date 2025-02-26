#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include <iostream>
#include "hotel.h"
#include <vector>

class BookingSystem {
private:
    std::vector<Hotel> hotels;

public:
    BookingSystem();
    ~BookingSystem();
    void add_hotel(const std::string& hotel_name);
    Hotel* find_hotel(const std::string& name);
    void print_hotels() const;
};

#endif
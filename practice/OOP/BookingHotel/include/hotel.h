#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include "room.h"
#include <vector>

class Hotel{
private:
    std::string hotel_name;
    std::vector<Room> rooms;

public:
    Hotel();
    Hotel(std::string hotel_name);
    ~Hotel();

    std::string get_hotel_name() const;
    void set_hotel_name(std::string hotel_name);

    void add_room(int room_number, int price_by_night, Room::RoomType type);
    void book_room(int room_number, const std::string& guest_name);
    void cancel_booking(int room_number);
    void print_rooms() const;
};


#endif
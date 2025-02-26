#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

class Room {
private:
    int room_number;
    int price_by_night;
    std::string guest_name;
    bool is_booked;

public:
    
    enum class RoomType {
        Economy, 
        Standard,
        Deluxe
    };
    RoomType room_type;

    Room();
    Room(int room_number, int price_by_night, RoomType room_type);
    ~Room();

    int get_room_number() const;
    int get_price_by_night() const;
    std::string get_guest_name() const;
    bool get_is_booked() const;
    RoomType get_room_type() const;

    void set_room_number(int room_number);
    void set_price_by_night(int price_by_night);
    void set_guest_name(std::string guest_name);
    void set_is_booked(bool is_booked);
    void set_room_type(RoomType room_type);

    void book(const std::string& guest_name);
    void cancel_booking();
    void print_info() const;

};

#endif
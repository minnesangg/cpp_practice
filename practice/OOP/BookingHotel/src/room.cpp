#include "room.h"

Room::Room(){
    room_number = 0;
    price_by_night = 0;
    guest_name = "No name";
    is_booked = false;
    room_type = RoomType::Economy;
}

Room::Room(int room_number, int price_by_night, RoomType room_type){
    this->room_number = room_number;
    this->price_by_night = price_by_night;
    this->room_type = room_type;
    guest_name = "No name";
    is_booked = false;
}

Room::~Room(){
    std::cout << "Room " << room_number << " is no longer exists!" << std::endl;
}


int Room::get_room_number() const{
    return room_number;
}

int Room::get_price_by_night() const{
    return price_by_night;
}

std::string Room::get_guest_name() const{
    return guest_name;
}

bool Room::get_is_booked() const{
    return is_booked;
}

Room::RoomType Room::get_room_type() const{
    return room_type;
}

void Room::set_room_number(int room_number){
    this->room_number = room_number;
}

void Room::set_price_by_night(int price_by_night){
    this->price_by_night = price_by_night;
}

void Room::set_guest_name(std::string guest_name){
    this->guest_name = guest_name;
}

void Room::set_is_booked(bool is_booked){
    this->is_booked = is_booked;
}

void Room::set_room_type(RoomType room_type){
    this->room_type = room_type;
}

void Room::book(const std::string& guest_name){
    if(is_booked){
        std::cout << "This room is booked!" << std::endl;
        return;
    }
    this->guest_name = guest_name;
    is_booked = true;
    std::cout << "Room " << room_number << " is booked by " << guest_name << std::endl;
}

void Room::cancel_booking(){
    if(!is_booked){
        std::cout << "This room is not booked!" << std::endl;
        return;
    }
    guest_name = "No name";
    is_booked = false;
    std::cout << "Booking of room " << room_number << " is canceled!" << std::endl;
}

void Room::print_info() const{
    std::cout << "Room number: " << room_number << std::endl;
    std::cout << "Price by night: " << price_by_night << std::endl;
    std::cout << "Room type: ";
    switch(room_type){
        case RoomType::Economy:
            std::cout << "Economy" << std::endl;
            break;
        case RoomType::Standard:
            std::cout << "Standard" << std::endl;
            break;
        case RoomType::Deluxe:
            std::cout << "Deluxe" << std::endl;
            break;
    }

    std::cout << "Is booked: " << (is_booked ? "Yes" : "No") << std::endl;
    if(is_booked){
        std::cout << "Guest name: " << guest_name << std::endl;
    }

    std::cout << std::endl;
}
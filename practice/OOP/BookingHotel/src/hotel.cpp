#include "hotel.h"

Hotel::Hotel(){
    hotel_name = "No name";
}

Hotel::Hotel(std::string hotel_name){
    this->hotel_name = hotel_name;
}

Hotel::~Hotel(){}

std::string Hotel::get_hotel_name() const{
    return hotel_name;
}

void Hotel::set_hotel_name(std::string hotel_name){
    this->hotel_name = hotel_name;
}

void Hotel::add_room(int room_number, int price_by_night, Room::RoomType type) {
    rooms.emplace_back(room_number, price_by_night, type);
}

void Hotel::print_rooms() const{
    std::cout << "Hotel " << hotel_name << " has the following rooms:" << std::endl;
    for (const auto& room : rooms) {
        room.print_info();
    }
}

void Hotel::book_room(int room_number, const std::string& guest_name){
    for(auto& room : rooms){
        if(room.get_room_number() == room_number){
            room.book(guest_name);
            return;
        }
    }
    std::cout << "Room " << room_number << " is not found!" << std::endl;
}

void Hotel::cancel_booking(int room_number){
    for(auto& room : rooms){
        if(room.get_room_number() == room_number){
            room.cancel_booking();
            return;
        }
    }
    std::cout << "Room " << room_number << " is not found!" << std::endl;
}


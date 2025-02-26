#include "booking_system.h"

BookingSystem::BookingSystem(){
    hotels.clear();
}

BookingSystem::~BookingSystem(){
    hotels.clear();
}

void BookingSystem::add_hotel(const std::string& hotel_name){
    hotels.emplace_back(hotel_name);
}

Hotel* BookingSystem::find_hotel(const std::string& name) {
    for (auto& hotel : hotels) {
        if (hotel.get_hotel_name() == name) {
            return &hotel;
        }
    }
    return nullptr; 
}


void BookingSystem::print_hotels() const{
    std::cout << "The booking system has the following hotels:" << std::endl;
    for(const auto& hotel : hotels){
        std::cout << hotel.get_hotel_name() << std::endl;
    }
}
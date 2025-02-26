#include <iostream>
#include "booking_system.h"

int main() {
    BookingSystem system;

    system.add_hotel("Grand Hotel");
    system.add_hotel("Sea Breeze Resort");
    system.add_hotel("Mountain View Lodge");

    system.find_hotel("Grand Hotel")->add_room(101, 100, Room::RoomType::Standard);
    system.find_hotel("Grand Hotel")->add_room(102, 150, Room::RoomType::Deluxe);
    system.find_hotel("Sea Breeze Resort")->add_room(201, 80, Room::RoomType::Economy);
    system.find_hotel("Mountain View Lodge")->add_room(301, 120, Room::RoomType::Standard);

    system.find_hotel("Grand Hotel")->print_rooms();
    system.find_hotel("Sea Breeze Resort")->print_rooms();
    system.find_hotel("Mountain View Lodge")->print_rooms();

    system.find_hotel("Grand Hotel")->book_room(101, "Alice");
    system.find_hotel("Sea Breeze Resort")->book_room(201, "Bob");

    std::cout << "\nПосле бронирования:\n";
    system.find_hotel("Grand Hotel")->print_rooms();
    system.find_hotel("Sea Breeze Resort")->print_rooms();
    
    system.find_hotel("Grand Hotel")->cancel_booking(101);
    
    std::cout << "\nПосле отмены бронирования:\n";
    system.find_hotel("Grand Hotel")->print_rooms();
    
    return 0;
}

#include <thread>
#include <iostream>
#include <chrono>

void printID(){
    std::thread::id id = std::this_thread::get_id();
    std::cout << "ID of current thread: " << id << std::endl;
}

void printNSleep(){
    printID();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    printID();

    std::cout << "Done" << std::endl;
}

int main(){
    std::thread t(printNSleep);
    std::thread t1(printNSleep);
    std::thread t2(printNSleep);

    t.join();
    t1.join();
    t2.join();
}
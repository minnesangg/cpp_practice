#include <iostream>
#include <thread>
#include <chrono>

void printNumbers(int id) {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread " << id << ": " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main(){

    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);
    std::thread t3(printNumbers, 3);

    t1.join();
    t2.detach();
    t3.join();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
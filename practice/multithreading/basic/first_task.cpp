#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void printID(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) { 
        cv.wait(lock);
    }

    std::cout << "Thread " << id << " is working\n";
}

void go() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    
    std::cout << "Ready to go!\n";
    ready = true;
    cv.notify_all(); 
}

int main() {
    std::thread threads[5];
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(printID, i);
    }

    go(); 

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

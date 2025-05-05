#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex cout_mutex;

void simulation(int id){
    for(int progress = 0; progress < 100; progress+=5){
        {
            std::unique_lock<std::mutex> lock(cout_mutex);
            std::cout << "[File " << id << "] Progress: " << progress << "%" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "[File " << id << "] Download complete!" << std::endl;
    }
}


int main(){

    const int fileCount = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < fileCount; ++i) {
        threads.emplace_back(simulation, i + 1);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All downloads finished!" << std::endl;
    return 0;
}
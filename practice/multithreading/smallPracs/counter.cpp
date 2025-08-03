#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter = 0;

void incCounter(){
    int local = 0;

    for(int i = 0; i < 1000; i++){
        local++;
    }

    counter += local;
}

int main(){
    const int threadsCount = 100;
    std::vector<std::thread> threads;
    threads.reserve(threadsCount);

    for(int i = 0; i < threadsCount; i++){
        threads.emplace_back(incCounter);
    }

    for (auto& t : threads){
        t.join();
    }

    std::cout << "Counter: " << counter << std::endl;
}
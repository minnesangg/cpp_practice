#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::queue<int> tasks;
std::condition_variable cv;
bool done = false;

void producer(){
    for(int i = 0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(i);
        std::cout << "[Producer] Added task " << i << std::endl;
        cv.notify_all();
    }

    std::unique_lock<std::mutex> lock(mtx);
    done = true;
    cv.notify_all();
}

void consumer(int id){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !tasks.empty() || done; });

        if(!tasks.empty()){
            int task = tasks.front();
            tasks.pop();
            lock.unlock();
            std::cout << "[Consumer " << id << "] Processing task " << task << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } else if(done){
            break;
        }
    }
    std::cout << "[Consumer " << id << "] Finished." << std::endl;
}

int main(){

    std::thread prod(producer);
    std::thread cons1(consumer, 1);
    std::thread cons2(consumer,2);

    prod.join();
    cons1.join();
    cons2.join();

    return 0;
}
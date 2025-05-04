#include <mutex>
#include <random>
#include <thread>
#include <iostream>
#include <vector>

using uint = unsigned int;

class ATM{
public:
    void withdrawMoney(uint money, uint clientID){
        std::lock_guard<std::mutex> lock(mtx);
        if (money <= balance) {
            balance -= money;
            std::cout << "Client " << clientID << " withdrew " << money
                      << " dollars. Remaining balance: " << balance << '\n';
        } else {
            std::cout << "Client " << clientID << " could not withdraw "
                      << money << " dollars. Not enough funds. Remaining balance: " << balance << '\n';
        }
    }

private:
    uint balance = 1000;
    std::mutex mtx;

};

int main(){
    ATM atm;
    std::vector<std::thread> threads;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(50, 200);


    for (int i = 1; i <= 10; ++i) {
        threads.emplace_back([&atm, i, amount = dist(gen)]() {
            atm.withdrawMoney(amount, i);
        });
    }

    for (auto& t : threads) {
        t.join();
    }


    return 0;
}
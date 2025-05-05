#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <random>
#include <string>
#include <chrono>

class Table{
private:
    bool isEmpty;
    int ID;
    std::mutex mtx;

public:
    Table(bool isEmpty, int ID) : isEmpty(isEmpty), ID(ID) {}
    
    Table(Table&& other) noexcept 
        : isEmpty(other.isEmpty), ID(other.ID) 
    {}

    Table& operator=(Table&& other) noexcept {
        if (this != &other) {
            std::lock_guard<std::mutex> lock(mtx);
            isEmpty = other.isEmpty;
            ID = other.ID;
        }
        return *this;
    }

    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;

    int getTableID(){
        return ID;
    }

    bool getIsEmpty(){
        std::lock_guard<std::mutex> lock(mtx);
        return isEmpty;
    }

    void setIsEmpty(bool isEmpty){
        std::lock_guard<std::mutex> lock(mtx);
        this->isEmpty = isEmpty;
    }

    bool trySeat(int visitorID, int timer){
        std::lock_guard<std::mutex> lock(mtx);
        if(!isEmpty){
            return false;
        }

        isEmpty = false;

        std::cout << "Visitor with ID: " << visitorID 
            << " seated at table: " << ID << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(timer));

        isEmpty = true;
        std::cout << "Visitor with ID: " << visitorID 
                  << " left table: " << ID << std::endl;

        return true;
    }

};

class Visitor {
private:
    std::string name;
    int visitorID;

public:
    Visitor(std::string name, int visitorID){
        this->name = name;
        this->visitorID = visitorID;
    }

    void seatDown(Table& table, int timer) {
        if (!table.trySeat(visitorID, timer)) {
            std::cout << "Visitor " << visitorID 
                      << " tried to sit at table " << table.getTableID() 
                      << ", but it's occupied.\n";
        }
    }

};

std::vector<Table> createTables() {
    std::vector<Table> tables;
    tables.emplace_back(true, 1);
    tables.emplace_back(true, 2);
    tables.emplace_back(true, 3);
    return tables;
}

std::vector<Visitor> createVisitors(){
    return {
        Visitor("Vlad", 1), Visitor("Bob", 2), Visitor("Alex", 3),
        Visitor("Steve", 4), Visitor("Alice", 5), Visitor("Theodor", 6)
    };
}

int main(){
    std::vector<Visitor> visitors = createVisitors();
    std::vector<Table> tables = createTables();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> tableDist(0, tables.size() - 1);
    std::uniform_int_distribution<> visitorDist(0, visitors.size() - 1);
    std::uniform_int_distribution<> timeDist(1, 3);

    const int MAX_ITER = 50; 
        for(int i = 0; i < MAX_ITER; ++i){
            int visitorIndex = visitorDist(gen);
            int tableIndex = tableDist(gen);
            int timer = timeDist(gen);

            std::thread([visitor = &visitors[visitorIndex], 
                         table = &tables[tableIndex], 
                         timer]() {
                visitor->seatDown(*table, timer);
            }).detach();

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}
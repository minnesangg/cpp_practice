#include "vector.h"
#include <iostream>
#include <string>

int main() {
    minnesang::Vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);
    intVec.push_back(30);

    std::cout << "intVec: ";
    for (size_t i = 0; i < intVec.get_size(); i++) {
        std::cout << intVec[i] << " ";
    }
    std::cout << std::endl;

    intVec.insert(1, 15);
    std::cout << "After insert: ";
    for (size_t i = 0; i < intVec.get_size(); i++) {
        std::cout << intVec[i] << " ";
    }
    std::cout << std::endl;

    intVec.erase(2);
    std::cout << "After erase: ";
    for (size_t i = 0; i < intVec.get_size(); i++) {
        std::cout << intVec[i] << " ";
    }
    std::cout << std::endl;

    minnesang::Vector<std::string> strVec;
    strVec.push_back("Hello");
    strVec.push_back("World");

    std::cout << "strVec: ";
    for (size_t i = 0; i < strVec.get_size(); i++) {
        std::cout << strVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

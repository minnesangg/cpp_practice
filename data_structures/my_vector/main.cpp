#include <iostream>
#include <stdexcept>
#include "mnsng_vector.h"

void print_vector(const minnesang::Vector<int>& vec) {
    for (size_t i = 0; i < vec.get_size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        minnesang::Vector<int> vec;  // creating vector

        for(int i = 0; i < 3; i++){
            vec.push_back(60);
            vec.push_back(20);     // adding elements
            vec.push_back(30);
            vec.push_back(40);
        }


        std::cout << "After push_back: ";
        print_vector(vec);

        vec.pop_back();  // deleting last element
        std::cout << "After pop_back: ";
        print_vector(vec);

        std::cout << "Element at index 1: " << vec[1] << std::endl;  // access element by index

        vec.insert(1, 25);        // inserting element
        std::cout << "After insert at index 1: ";
        print_vector(vec);

        vec.erase(2);     // removing element by index
        std::cout << "After erase at index 2: ";
        print_vector(vec);

        std::cout << "Capacity: " << vec.get_capacity() << std::endl; // showing capacity
        std::cout << "Does vector contain 30? " << (vec.contains(30) ? "Yes" : "No") << std::endl;
        std::cout << "Index of 25: " << vec.index_of(25) << std::endl;

        std::cout << "Is vector empty? " << (vec.is_empty() ? "Yes" : "No") << std::endl;   // check if empty

        std::cout << "Front: " << vec.front() << ", Back: " << vec.back() << std::endl;   // first and last element

        std::cout << "Is vector sorted? " << (vec.is_sorted() ? "Yes" : "No") << std::endl;  // check if sorted

        std::cout << "After quickSort: ";
        vec.quickSort(0, vec.get_size() - 1);  // Sort 
        print_vector(vec);

        std::cout << "Performing binary search for 60:" << std::endl;
        int index = vec.binary_search(60);  
        if (index != -1) {
            std::cout << "Value found at index: " << index << std::endl;
        } else {
            std::cout << "Value not found" << std::endl;
        }

        vec.clear();    // clearing 
        std::cout << "After clear: ";
        print_vector(vec);
        std::cout << "Size after clear: " << vec.get_size() << std::endl;

        vec.shrink_to_fit();  // shrinking 
        std::cout << "After shrink_to_fit: ";
        print_vector(vec);
        std::cout << "Size after shrink_to_fit: " << vec.get_size() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
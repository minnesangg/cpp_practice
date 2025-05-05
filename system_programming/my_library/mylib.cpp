#include <iostream>

extern "C" {
    void Hello() {
        std::cout << "Hello world!" << std::endl;
    }

    int Add(int a, int b) {
        return a + b;
    }
}

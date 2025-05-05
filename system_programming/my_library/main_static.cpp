#include <iostream>

extern "C" void Hello();
extern "C" int Add(int, int);

int main() {
    Hello();
    std::cout << "2 + 3 = " << Add(2, 3) << std::endl;
    return 0;
}

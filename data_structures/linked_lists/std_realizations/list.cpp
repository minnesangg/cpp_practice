#include <iostream>
#include <list>

void list_print(std::list<int> lst) {
    for (int x : lst) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_front(0);
    lst.push_back(6);
    list_print(lst);

    lst.pop_back();
    list_print(lst);

    lst.pop_front();
    list_print(lst);

    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.remove(2);
    list_print(lst);

    lst.reverse();
    list_print(lst);

    return 0;
}
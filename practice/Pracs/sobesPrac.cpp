#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1, 2, 3, 2, 50, -100};

    int delElem = 2, counter = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i] != delElem){
            v[counter] = v[i];
            counter++;
        }
    }

    for(int i : v){
        std::cout << i << ' ';
    }
}
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1,2,-10,50,3,6,-100,20};

    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] > v[j]){
                std::swap(v[i], v[j]);
            }
        }
    }

    for(int i : v){
        std::cout << i << ' ';
    }
}
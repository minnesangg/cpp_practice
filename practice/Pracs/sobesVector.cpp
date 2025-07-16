#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> doubleIfEven(const std::vector<int>& inputV){
    std::vector<int> result;

    for(int i : inputV){
        if(i % 2 == 0){
            result.push_back(i * i);
        } else {
            result.push_back(i);
        }
    }

    std::sort(result.begin(), result.end());

    return result;
}

int main(){
    std::vector<int> v = {1,2,3,7,9,20,15,8};

    std::vector<int> result = doubleIfEven(v);

    for(int i : result){
        std::cout << i << '\n';
    }
}
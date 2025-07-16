#include <iostream>
#include <vector>
#include <set>

std::vector<int> deleteDublicates(const std::vector<int>& inputV){
    std::vector<int> result;

    std::set<int> s(inputV.begin(), inputV.end());

    result.assign(s.begin(), s.end());

    return result;
}

int main(){
    std::vector<int> v = {1,1,1,2,3,4,4,5};

    std::vector<int> result = deleteDublicates(v);

    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << '\n';
    }
}
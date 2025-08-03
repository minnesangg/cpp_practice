#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

std::vector<std::vector<int>> divideArrayByN(const int n, const std::vector<int>& nums){
    const int step = nums.size() / n;
    std::vector<std::vector<int>> groups(n);
    int remainder = nums.size() % n;

    auto it = nums.begin();
    for (int i = 0; i < n; i++) {
        int group_size = step + (remainder > 0 ? 1 : 0);

        if (remainder > 0) --remainder;
        groups[i].insert(groups[i].end(), it, it + group_size);
        it += group_size;
    }
    return groups;
}

void sumOfSubArrays(const std::vector<int>& nums, int& result){
    result = std::accumulate(nums.begin(), nums.end(), 0);
}

int main(){
    const int n = 5;
    const std::vector<int> nums = {1,2,5,7,9,3,0,1,10,4};

    const std::vector<std::vector<int>> groups = divideArrayByN(n, nums);
    std::vector<std::thread> threads;
    std::vector<int> partial_sums(n, 0);

    for (int i = 0; i < n; i++) {
        threads.emplace_back(sumOfSubArrays, std::cref(groups[i]), std::ref(partial_sums[i]));
    }

    for (auto& t : threads) {
        t.join();
    }

    int totalSum = std::accumulate(partial_sums.begin(), partial_sums.end(), 0);
    std::cout << "Total sum: " << totalSum << std::endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::pair<int,int> topElems(const std::vector<int>& v) {
    std::unordered_map<int, int> elements;
    for (int num : v) {
        elements[num]++;
    }

    auto it = std::max_element(
        elements.begin(), elements.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );
    return *it;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 2, 2, 2};

    auto result = topElems(v);

    std::cout << "Element: " << result.first << ", Count: " << result.second << '\n';
}

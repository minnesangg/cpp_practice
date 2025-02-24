#include <iostream>
#include <vector>

using namespace std;

int recurs(vector<int> nums, int index = 0)
{
    if (index >= nums.size())
    {
        return 0;
    }
    return 1 + recurs(nums, index + 1);
}

int maxValue(const vector<int> &nums, int index = 0)
{
    if (index == nums.size() - 1)
    {
        return nums[index];
    }
    int max_in_rest = maxValue(nums, index + 1);
    return max(nums[index], max_in_rest);
}

int main()
{
    vector<int> nums{2, 3, 6};
    cout << "Задание на кол-во элементов: " << recurs(nums) << endl;
    cout << "Задание на максимальное число: " << maxValue(nums) << endl;

    return 0;
}
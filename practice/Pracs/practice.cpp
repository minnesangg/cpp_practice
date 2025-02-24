#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pairedNums(vector<int> &nums)
{
    vector<int> paired;
    vector<int> unpaired;
    vector<int> sorted;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] % 2 == 0)
        {
            paired.push_back(nums[i]);
        }
        else if (nums[i] % 2 != 0)
        {
            unpaired.push_back(nums[i]);
        }
    }
    sort(paired.begin(), paired.end());
    sort(unpaired.rbegin(), unpaired.rend());

    sorted.insert(sorted.end(), paired.begin(), paired.end());
    sorted.insert(sorted.end(), unpaired.begin(), unpaired.end());

    return sorted;
}

int main()
{
    vector<int> nums = {1, 4, 5, 12, 10, 9, 81};
    vector<int> result = pairedNums(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
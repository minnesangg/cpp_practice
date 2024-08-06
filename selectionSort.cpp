#include <iostream>
#include <vector>

using namespace std;

int find_smallest(const vector<int> &nums)
{
    int smallest = nums[0];
    int smallestIndex = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

vector<int> selection_sort(vector<int> nums)
{
    vector<int> sortedArray;
    while (!nums.empty())
    {
        int smallestIndex = find_smallest(nums);
        sortedArray.push_back(nums[smallestIndex]);
        nums.erase(nums.begin() + smallestIndex);
    }
    return sortedArray;
}

int main()
{
    vector<int> nums{12, 4, 3, 15, 62, 1};
    vector<int> sorted = selection_sort(nums);

    cout << "Selection sort: ";
    for (int num : sorted)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
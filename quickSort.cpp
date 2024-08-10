#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> nums)
{
    int size = nums.size();
    if (size < 2)
        return nums;

    int pivotIndex = rand() % size;
    int pivot = nums[pivotIndex];

    vector<int> less;
    vector<int> greater;

    for (int i = 1; i < size; i++)
    {
        if (nums[i] <= pivot)
        {
            less.push_back(nums[i]);
        }
        else
        {
            greater.push_back(nums[i]);
        }
    }
    less = quickSort(less);
    greater = quickSort(greater);

    less.push_back(pivot);
    less.insert(less.end(), greater.begin(), greater.end());

    return less;
}

int main()
{
    vector<int> nums{3, 2, 1, 5, 10};
    vector<int> res = quickSort(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
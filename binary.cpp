#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &nums, int key)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == nums[mid])
            return mid;
        if (nums[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{1, 2, 4, 6, 13, 15, 17};
    int key = 13;
    int result = binarySearch(nums, key);

    if (result != -1)
    {
        cout << "Element " << key << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << key << " not found" << endl;
    }

    return 0;
}

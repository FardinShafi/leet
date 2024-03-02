#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int left = 2;
        for (int right = 2; right < nums.size(); right++)
        {
            if (nums[right] != nums[left - 2])
            {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3}; // Example input

    // Call the removeDuplicates function
    int newSize = solution.removeDuplicates(nums);

    // Output the new size of the vector and its contents
    cout << "New size: " << newSize << endl;
    cout << "Updated vector: ";
    for (int i = 0; i < newSize; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

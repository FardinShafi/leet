#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (indexMap.find(nums[i]) != indexMap.end())
            {
                if (i - indexMap[nums[i]] <= k)
                {
                    return true;
                }
            }
            indexMap[nums[i]] = i;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Example 1: " << sol.containsNearbyDuplicate(nums1, 3) << endl; // Output: true

    vector<int> nums2 = {1, 0, 1, 1};
    cout << "Example 2: " << sol.containsNearbyDuplicate(nums2, 1) << endl; // Output: true

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    cout << "Example 3: " << sol.containsNearbyDuplicate(nums3, 2) << endl; // Output: false

    return 0;
}

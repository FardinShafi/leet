#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int res = 0;
        int l = 0, r = 0;

        while (r < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            {
                farthest = std::max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res += 1;
        }

        return res;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input

    int jumps = solution.jump(nums);

    cout << "Minimum number of jumps to reach the last index: " << jumps << endl;

    return 0;
}
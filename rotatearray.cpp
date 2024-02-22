#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size(); 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    solution.rotate(nums1, k1);
    cout << "Input: nums = [1,2,3,4,5,6,7], k = 3\n";
    cout << "Output: [";
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i];
        if (i != nums1.size() - 1)
            cout << ",";
    }
    cout << "]\n";

    return 0;
}

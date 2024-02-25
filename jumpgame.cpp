#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    
    for (int i = 0; i < n; ++i) {
        if (i > farthest) {
          
            return false;
        }
        farthest = max(farthest, i + nums[i]);
        if (farthest >= n - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << boolalpha << canJump(nums1) << endl; 
    cout << boolalpha << canJump(nums2) << endl; 

    return 0;
}

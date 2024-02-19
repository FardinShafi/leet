#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int len1 = solution.removeDuplicates(nums1);
    cout << "Length after removing duplicates: " << len1 << endl;
    cout << "Resultant array: ";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len2 = solution.removeDuplicates(nums2);
    cout << "Length after removing duplicates: " << len2 << endl;
    cout << "Resultant array: ";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
        int x = nums.size();
        int k = 0; 

        for (int i = 0; i < x; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
}

int main() {
    // Example test cases
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int expected1[] = {2, 2};
    int expectedLength1 = sizeof(expected1) / sizeof(expected1[0]);

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int expected2[] = {0, 1, 4, 0, 3};
    int expectedLength2 = sizeof(expected2) / sizeof(expected2[0]);

    // Test case 1
    int k1 = removeElement(nums1, val1);
    cout << "Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i];
        if (i != k1 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    // Test case 2
    int k2 = removeElement(nums2, val2);
    cout << "Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i];
        if (i != k2 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

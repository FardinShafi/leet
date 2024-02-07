#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        for (int i = nonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> myVector = {1, 2, 0, 3, 4, 0, 5, 6};

    cout << "Original Vector: ";
    for (int i =0; i<myVector.size();i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    solution.moveZeroes(myVector);

    cout << "Modified Vector: ";
    for (int i =0; i<myVector.size();i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    return 0;
}

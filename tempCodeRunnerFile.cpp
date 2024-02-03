include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0){
                nums.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                i--;
            }
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
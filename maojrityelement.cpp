#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int majority = 0;
        int n = nums.size();

        for (int num : nums) {
            if (++count[num] > n / 2) {
                majority = num;
                break;
            }
        }
        return majority;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majorityElement = solution.majorityElement(nums);
    
    cout << "The majority element is: " << majorityElement << endl;
    
    return 0;
}

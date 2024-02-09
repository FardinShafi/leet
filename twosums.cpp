#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;
        vector<int> result;
        
        for (int i=0; i<nums.size(); i++){
            int remain =target -nums[i];
            //if(mapping.count(remain) > 0) higher runtime
            if(mapping.find(remain) != mapping.end()){
                result.push_back(mapping[remain]);
                result.push_back(i);
            }
            mapping[nums[i]] = i;
        }

        return result;
    }
};

int main(){
    
    Solution sol;
    vector<int> nums = {2, 7, 11, 15}; 
    int target = 9; 

    vector<int> indices = sol.twoSum(nums, target); 
    cout << "Indices of the two numbers that add up to the target: ";
    for (int i = 0; i < indices.size(); ++i) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}
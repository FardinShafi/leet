#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int currentSum = numbers[left] + numbers[right];
            if (currentSum == target)
            {
                return {left + 1, right + 1};
            }
            else if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {};
    }
};

int main()
{
    Solution solution;

    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    for (int index : result1)
    {
        cout << index << " ";
    }
    cout << endl; // Output: 1 2

    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    for (int index : result2)
    {
        cout << index << " ";
    }
    cout << endl; // Output: 1 3

    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    for (int index : result3)
    {
        cout << index << " ";
    }
    cout << endl; // Output: 1 2

    return 0;
}

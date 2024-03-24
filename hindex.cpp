#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(
            citations.begin(), citations.end(),
            greater<int>());

        int n = citations.size();
        int h_index = 0;

        for (int i = 0; i < n; ++i)
        {
            if (citations[i] >= i + 1)
            {
                h_index = i + 1;
            }
            else
            {
                break;
            }
        }

        return h_index;
    }
};

int main()
{
    Solution s;
    // Example usage:
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << "Output for Example 1: " << s.hIndex(citations1) << endl; // Output: 3

    vector<int> citations2 = {1, 3, 1};
    cout << "Output for Example 2: " << s.hIndex(citations2) << endl; // Output: 1

    return 0;
}

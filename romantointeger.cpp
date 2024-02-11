#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int x = 0;
        int prev = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int value = romanValues[s[i]];
            if (value < prev)
            {
                x -= value;
            }
            else
            {
                x += value;
            }
            prev = value;
        }
        return x;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}
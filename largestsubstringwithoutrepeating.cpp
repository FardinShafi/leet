#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> charIndex(128, -1);

        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end)
        {
            char currentChar = s[end];
            if (charIndex[currentChar] >= start)
            {
                maxLength = max(maxLength, end - start);
                start = charIndex[currentChar] + 1;
            }
            charIndex[currentChar] = end;
        }

        maxLength = max(maxLength, static_cast<int>(s.length()) - start);

        return maxLength;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}

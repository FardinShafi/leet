#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Base cases: single character and adjacent characters
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
            }
        }

        // Iterate for lengths greater than 2
        for (int length = 3; length <= n; length++)
        {
            for (int i = 0; i <= n - length; i++)
            {
                int j = i + length - 1;
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }

        // Find starting index and length of longest palindrome
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] && j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, max_len);
    }
};

int main()
{
    string text = "babad";
    Solution solution; // Create an object of the Solution class
    string result = solution.longestPalindrome(text);
    cout << "Longest palindrome in '" << text << "': " << result << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            if (!isalnum(s[l]))
            {
                l++;
            }
            else if (!isalnum(s[r]))
            {
                r--;
            }
            else if (s[l] != s[r])
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string str = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(str) << endl;
    return 0;
}

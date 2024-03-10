#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int point = 0;
        for (int i = 0; i < t.length(); i++)
        {
            if (s[point] == t[i])
            {
                point++;
            }
        }
        if (point == s.length())
        {
            return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isSubsequence("abc", "ahyobdfkhc") << endl;
    return 0;
}

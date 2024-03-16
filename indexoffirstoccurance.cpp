#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int found = haystack.find(needle);
        if (found > -1)
        {
            return haystack.find(needle);
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.strStr("hello my name is ninoooooooooo. im an idiot sandwich. ninoooooooooooo", "nino") << endl;

    return 0;
}
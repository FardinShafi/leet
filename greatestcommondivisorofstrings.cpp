#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        while (str1 != str2)
        {
            if (str1.size() < str2.size())
                swap(str1, str2);
            if (str1.substr(0, str2.size()) == str2)
                str1 = str1.substr(str2.size());
            else
                return "";
        }
        return str1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.gcdOfStrings("ABCABC", "ABC") << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int count = 0;
        int k = 0;
        int prevcount = 100;
        if (strs.empty())
        {
            return "";
        }
        bool hasEmptyString = any_of(strs.begin(), strs.end(), [](const string &str){ return str.empty(); });

        if (hasEmptyString){
            return "";
        }

        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = 0; j < strs[i].length(); j++)
            {
                string s = strs[k];
                string t = strs[i];
                if (s[0] != t[0])
                {
                    return "";
                }
                else if (j != 0 && s[j - 1] != t[j - 1])
                {
                    break;
                }
                else if (i == 0 || s[j] == t[j])
                {
                    // cout << "K" << k << endl;
                    count = j;
                    // cout << count << endl;
                }
            }
            if (count == prevcount || count < prevcount)
            {
                prevcount = count;
                // cout << "prev" << prevcount << endl;
                k = i;
            }
            else{count=prevcount;}
        }
        // cout<<count+1<<endl;
        string substr = strs[0].substr(0, count + 1);
        return substr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> strs = {"acc","aaa","aaba"};
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}
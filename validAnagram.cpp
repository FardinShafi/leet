#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string &s, string &t)
    {
        unordered_map<char, int> letterCount;
        for (char ch : s)
        {
            letterCount[ch]++;
        }
        for (char ch : t)
        {
            if (letterCount.find(ch) == letterCount.end() || letterCount[ch] == 0)
            {
                return false;
            }
            letterCount[ch]--;
        }

        for (const auto &pair : letterCount)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    string s = "anagram";
    string t = "nagaram";

    bool result = solution.isAnagram(s, t);

    if (result)
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}

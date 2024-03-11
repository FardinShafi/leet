#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string &ransomNote, string &magazine)
    {
        unordered_map<char, int> charFreq;
        for (char ch : magazine)
            charFreq[ch]++;
        for (char ch : ransomNote)
        {
            if (charFreq[ch] <= 0)
            {
                return false;
            }
            charFreq[ch]--;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string ransomNote1 = "a", magazine1 = "b";
    string ransomNote2 = "aa", magazine2 = "ab";
    string ransomNote3 = "aa", magazine3 = "aab";

    cout << sol.canConstruct(ransomNote1, magazine1) << endl; // Output: false
    cout << sol.canConstruct(ransomNote2, magazine2) << endl; // Output: false
    cout << sol.canConstruct(ransomNote3, magazine3) << endl; // Output: true

    return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> charFreq;

        for (char c : s)
        {
            charFreq[c]++;
        }

        multiset<pair<int, char>, greater<pair<int, char>>> sortedChars;

        for (const auto &entry : charFreq)
        {
            sortedChars.insert({entry.second, entry.first});
        }
        string sortedString;
        for (const auto &entry : sortedChars)
        {
            sortedString += string(entry.first, entry.second);
        }

        return sortedString;
    }
};

int main()
{

    Solution solution;
    string s = "habijabi";
    cout << solution.frequencySort(s);

    return 0;
}
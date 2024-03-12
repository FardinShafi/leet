#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> charToWordMap;
        unordered_map<string, char> wordToCharMap;

        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word)
        {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.length(); ++i)
        {
            char c = pattern[i];
            string currentWord = words[i];
            if (charToWordMap.find(c) != charToWordMap.end() &&
                charToWordMap[c] != currentWord)
                return false;
            if (wordToCharMap.find(currentWord) != wordToCharMap.end() &&
                wordToCharMap[currentWord] != c)
                return false;
            charToWordMap[c] = currentWord;
            wordToCharMap[currentWord] = c;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string pattern1 = "abba", s1 = "dog cat cat dog";
    string pattern2 = "abba", s2 = "dog cat cat fish";
    string pattern3 = "aaaa", s3 = "dog cat cat dog";

    // Test the wordPattern function
    cout << "Test case 1: " << (sol.wordPattern(pattern1, s1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (sol.wordPattern(pattern2, s2) ? "true" : "false") << endl;
    cout << "Test case 3: " << (sol.wordPattern(pattern3, s3) ? "true" : "false") << endl;

    return 0;
}

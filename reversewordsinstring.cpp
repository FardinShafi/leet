#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> slot;
        stringstream ss(s);
        string word = "";
        while (getline(ss, word, ' ')) {
            if (!word.empty()) 
                slot.push_back(word);
        }
        s = "";
        for (auto it = slot.rbegin(); it != slot.rend(); ++it) {
            s += *it;
            if (it + 1 != slot.rend()){
                s += " ";
            }

        }

        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseWords("My name Is mr Shane")<<endl;
    return 0;
}
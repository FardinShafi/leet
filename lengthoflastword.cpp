#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            length = word.length();
        }

        return length;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "Today is a nice day";

    // Output results
    int result1 = solution.lengthOfLastWord(s1);
    int result2 = solution.lengthOfLastWord(s2);
    int result3 = solution.lengthOfLastWord(s3);
    int result4 = solution.lengthOfLastWord(s4);

    // Display results
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;
    cout << "Result 4: " << result4 << endl;

    return 0;
}

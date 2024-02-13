#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> perastack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                perastack.push(c);
            }
            else
            {
                if (perastack.empty())
                    return false;
                if ((c == ')' && perastack.top() != '(') ||
                    (c == '}' && perastack.top() != '{') ||
                    (c == ']' && perastack.top() != '['))
                {
                    return false;
                }
                perastack.pop();
            }
        }
        return perastack.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isValid("[()()()()({}{}{}{}{})]") << endl;

    return 0;
}

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int squaredSum(int num)
    {
        int sum = 0;
        while (num)
        {
            int d = num % 10;
            sum += d * d;
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> key;
        while (key.find(n) == key.end())
        {
            key.insert(n);
            n = squaredSum(n);
            if (n == 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    int number;
    cout << "Enter a number to check if it's a happy number: ";
    cin >> number;
    if (solution.isHappy(number))
    {
        cout << number << " is a happy number." << endl;
    }
    else
    {
        cout << number << " is not a happy number." << endl;
    }
    return 0;
}

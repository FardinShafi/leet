#include <iostream>
#include <limits>

// Function definition for reverse
int reverse(int x)
{
    int reversed = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;
        if (reversed > std::numeric_limits<int>::max() / 10 ||
            (reversed == std::numeric_limits<int>::max() / 10 && digit > 7))
            return 0;
        if (reversed < std::numeric_limits<int>::min() / 10 ||
            (reversed == std::numeric_limits<int>::min() / 10 && digit < -8))
            return 0;
        reversed = reversed * 10 + digit;
    }
    return reversed;
}

int main()
{
    // Test cases
    int test1 = 123;
    int test2 = -123;
    int test3 = 120;

    // Output the results
    std::cout << "Test 1: " << test1 << " -> " << reverse(test1) << std::endl;
    std::cout << "Test 2: " << test2 << " -> " << reverse(test2) << std::endl;
    std::cout << "Test 3: " << test3 << " -> " << reverse(test3) << std::endl;

    return 0;
}

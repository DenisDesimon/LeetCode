//#3536 Maximum Product of Two Digits - https://leetcode.com/problems/maximum-product-of-two-digits/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int firstDigit = 0, secondDigit = 0;
        while(n)
        {
            int cur = n % 10;
            if(cur >= firstDigit)
            {
                secondDigit = firstDigit;
                firstDigit = cur;
            }else
                secondDigit = max(secondDigit, cur);
            n = n / 10;
        }
        return firstDigit * secondDigit;
    }
};

int main()
{
    Solution solution;
    int givenN = 31;
    int expectedAnswer = 3;
    assert(solution.maxProduct(givenN) == expectedAnswer);

    givenN = 124;
    expectedAnswer = 8;
    assert(solution.maxProduct(givenN) == expectedAnswer);

    return 0;
}

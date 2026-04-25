//#3908 Valid Digit Number - https://leetcode.com/problems/valid-digit-number/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        bool isValid = false;
        while(n >= 10)
        {
            if(n % 10 == x)
                isValid = true;
            n /= 10;
        }
        return isValid && n != x;
    }
};

int main()
{
    Solution solution;
    int givenN = 101;
    int givenX = 0;
    bool expectedAnswer = true;
    assert(solution.validDigit(givenN, givenX) == expectedAnswer);

    givenN = 232;
    givenX = 2;
    expectedAnswer = false;
    assert(solution.validDigit(givenN, givenX) == expectedAnswer);

    return 0;
}

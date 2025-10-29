//#3370 Smallest Number With All Set Bits - https://leetcode.com/problems/smallest-number-with-all-set-bits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n;
    }
};

int main()
{
    Solution solution;
    int givenN = 5;
    int expectedAnswer = 7;
    assert(solution.smallestNumber(givenN) == expectedAnswer);

    givenN = 10;
    expectedAnswer = 15;
    assert(solution.smallestNumber(givenN) == expectedAnswer);

    return 0;
}

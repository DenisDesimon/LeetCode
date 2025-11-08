//#1611 Minimum One Bit Operations to Make Integers Zero - https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;
        int nextPower = 0;
        while((1 << nextPower) <= n)
            nextPower++;
        return (1 << nextPower) - 1 - minimumOneBitOperations(n - (1 << (nextPower - 1)));
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int expectedAnswer = 2;
    assert(solution.minimumOneBitOperations(givenN) == expectedAnswer);

    givenN = 6;
    expectedAnswer = 4;
    assert(solution.minimumOneBitOperations(givenN) == expectedAnswer);

    return 0;
}

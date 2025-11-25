//#1015 Smallest Integer Divisible by K - https://leetcode.com/problems/smallest-integer-divisible-by-k/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for(int length = 1; length <= k; length++)
        {
            remainder = (remainder * 10 + 1) % k;
            if(remainder == 0)
                return length;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int givenNums = 3;
    int expectedAnswer = 3;
    assert(solution.smallestRepunitDivByK(givenNums) == expectedAnswer);

    givenNums = 2;
    expectedAnswer = -1;
    assert(solution.smallestRepunitDivByK(givenNums) == expectedAnswer);

    return 0;
}

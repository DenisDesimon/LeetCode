//#1411 Number of Ways to Paint N × 3 Grid - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        long long pattern121 = 6, pattern123 = 6, sum121, sum123, mod = 1e9 + 7;
        for(int i = 1; i < n; i++)
        {
            sum121 = pattern121 * 3 + pattern123 * 2;
            sum123 = pattern121 * 2 + pattern123 * 2;
            pattern121 = sum121 % mod;
            pattern123 = sum123 % mod;
        }
        return (pattern121 + pattern123) % mod;
    }
};

int main()
{
    Solution solution;
    int givenN = 5000;
    int expectedAnswer = 30228214;
    assert(solution.numOfWays(givenN) == expectedAnswer);

    givenN = 1;
    expectedAnswer = 12;
    assert(solution.numOfWays(givenN) == expectedAnswer);

    return 0;
}

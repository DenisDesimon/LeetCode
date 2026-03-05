//#3857 Minimum Cost to Split into Ones - https://leetcode.com/problems/minimum-cost-to-split-into-ones/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCost(int n) {
        return (n) * (n - 1) / 2;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int expectedAnswer = 3;
    assert(solution.minCost(givenN) == expectedAnswer);

    givenN = 4;
    expectedAnswer = 6;
    assert(solution.minCost(givenN) == expectedAnswer);

    return 0;
}

//#3789 Minimum Cost to Acquire Required Items  - https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long result = 0;
        if(costBoth < cost1 + cost2)
        {
            long long takes = min(need1, need2);
            result = takes * costBoth;
            need1 -= takes;
            need2 -= takes;
        }
        result += (long long)need1 * min(cost1, costBoth);
        result += (long long)need2 * min(cost2, costBoth);
        return result;
    }
};

int main()
{
    Solution solution;
    int givenCost1 = 3;
    int givenCost2 = 2;
    int givenCostBoth = 1;
    int givenNeed1 = 3;
    int givenNeed2 = 2;
    int expectedAnswer = 3;
    assert(solution.minimumCost(givenCost1, givenCost2, givenCostBoth, givenNeed1, givenNeed2) == expectedAnswer);

    givenCost1 = 5;
    givenCost2 = 4;
    givenCostBoth = 15;
    givenNeed1 = 0;
    givenNeed2 = 0;
    expectedAnswer = 0;
    assert(solution.minimumCost(givenCost1, givenCost2, givenCostBoth, givenNeed1, givenNeed2) == expectedAnswer);

    return 0;
}

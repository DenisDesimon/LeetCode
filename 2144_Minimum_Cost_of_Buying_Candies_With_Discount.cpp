//#2144 Minimum Cost of Buying Candies With Discount - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0;
        for(int i = 0; i < (int)cost.size(); i++)
        {
            if(i % 3 == 2)
                continue;
            sum += cost[i];
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCosts = {1, 2, 3};
    int expectedAnswer = 5;
    assert(solution.minimumCost(givenCosts) == expectedAnswer);

    givenCosts = {6, 5, 7, 9, 2, 2};
    expectedAnswer = 23;
    assert(solution.minimumCost(givenCosts) == expectedAnswer);

    return 0;
}

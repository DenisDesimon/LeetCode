//#1406 Stone Game III - https://leetcode.com/problems/stone-game-iii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1);
        for(int i = n - 1; i >= 0; i--)
        {
            int sum = 0;
            int cur = INT_MIN;
            for(int j = 0; j < 3 && i + j < n; j++)
            {
                sum += stoneValue[i + j];
                cur = max(cur, sum - dp[i + j + 1]);
            }
            dp[i] = cur;
        }
        if(dp.front() > 0)
            return "Alice";
        if(dp.front() < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    Solution solution;
    vector<int> givenStones = {1, 2, 3, 7};
    string expectedAnswer = "Bob";
    assert(solution.stoneGameIII(givenStones) == expectedAnswer);

    givenStones = {1, 2, 3, -9};
    expectedAnswer = "Alice";
    assert(solution.stoneGameIII(givenStones) == expectedAnswer);

    return 0;
}

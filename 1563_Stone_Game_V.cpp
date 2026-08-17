//#1563 Stone Game V - https://leetcode.com/problems/stone-game-v/
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
    int dfs(int left, int right, vector<int>& stoneValue, vector<vector<int>> &dp){
        if(left == right)
            return 0;
        if(dp[left][right])
            return dp[left][right];
        int sumSegment = accumulate(stoneValue.begin() + left, stoneValue.begin() + right + 1, 0);
        int sumLeft = 0;
        for(int i = left; i < right; i++)
        {
            sumLeft += stoneValue[i];
            int sumRight = sumSegment - sumLeft;
            if(sumLeft < sumRight)
                dp[left][right] = max(dp[left][right], dfs(left, i, stoneValue, dp) + sumLeft);
            else if(sumLeft > sumRight)
                dp[left][right] = max(dp[left][right], dfs(i + 1, right, stoneValue, dp) + sumRight);
            else
                dp[left][right] = max(dp[left][right], max(dfs(left, i, stoneValue, dp), dfs(i + 1, right, stoneValue, dp)) + sumLeft);
        }
        return dp[left][right];
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int> (n));
        return dfs(0, n - 1, stoneValue, dp);
    }
};

int main()
{
    Solution solution;
    vector<int> givenStones = {6, 2, 3, 4, 5, 5};
    int expectedAnswer = 18;
    assert(solution.stoneGameV(givenStones) == expectedAnswer);

    givenStones = {7, 7, 7, 7, 7, 7, 7};
    expectedAnswer = 28;
    assert(solution.stoneGameV(givenStones) == expectedAnswer);


    return 0;
}

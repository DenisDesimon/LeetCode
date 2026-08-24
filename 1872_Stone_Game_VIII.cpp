//#1872 Stone Game VIII - https://leetcode.com/problems/stone-game-viii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1);
        for(int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + stones[i - 1];
        vector<int> dp(n);
        dp[n - 1] = prefix[n];
        for(int i = n - 2; i > 0; i--)
        {
            dp[i] = max(dp[i + 1], prefix[i + 1] - dp[i + 1]);
        }
        return dp[1];
    }
};

int main()
{
    Solution solution;
    vector<int> givenStones = {-1, 2, -3, 4, -5};
    int expectedAnswer = 5;
    assert(solution.stoneGameVIII(givenStones) == expectedAnswer);

    givenStones = {7, -6, 5, 10, 5, -2, -6};
    expectedAnswer = 13;
    assert(solution.stoneGameVIII(givenStones) == expectedAnswer);


    return 0;
}

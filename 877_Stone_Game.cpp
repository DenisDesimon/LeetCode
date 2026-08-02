//#877 Stone Game - https://leetcode.com/problems/stone-game/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(piles);
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 3, 4, 5};
    bool expectedAnswer = true;
    assert(solution.stoneGame(givenNums) == expectedAnswer);

    givenNums = {3, 7, 2, 3};
    expectedAnswer = true;
    assert(solution.stoneGame(givenNums) == expectedAnswer);

    return 0;
}

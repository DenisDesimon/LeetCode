//#1155 Number of Dice Rolls With Target Sum - https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for(int i = 1; i <= target && i <= k; i++)
            dp[1][i] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < target; j++)
            {
                if(dp[i][j] == 0)
                    continue;
                for(int dice = 1; dice <= k; dice++)
                {
                    if(j + dice <= target)
                    {
                        dp[i + 1][j + dice] += dp[i][j];
                        dp[i + 1][j + dice] %= mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};


int main()
{
    Solution solution;
    int given_n = 1;
    int given_k = 6;
    int given_target = 3;
    int expected_answer = 1;
    assert(solution.numRollsToTarget(given_n, given_k, given_target) == expected_answer);

    given_n = 30;
    given_k = 30;
    given_target = 500;
    expected_answer = 222616187;
    assert(solution.numRollsToTarget(given_n, given_k, given_target) == expected_answer);

    return 0;
}

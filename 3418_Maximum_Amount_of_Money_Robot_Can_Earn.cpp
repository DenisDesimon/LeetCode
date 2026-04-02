//#3418 Maximum Amount of Money Robot Can Earn - https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins.front().size();
        vector<vector<int>> dp0(n + 1, vector<int>(m + 1, INT_MIN / 2));
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, INT_MIN / 2));
        vector<vector<int>> dp2(n + 1, vector<int>(m + 1, INT_MIN / 2));
        dp0[0][1] = dp0[1][0] = dp1[0][1] = dp1[0][1] = dp2[0][1] = dp2[0][1] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(coins[i - 1][j - 1] >= 0)
                {
                    dp0[i][j] = max(dp0[i - 1][j], dp0[i][j - 1]) + coins[i - 1][j - 1];
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + coins[i - 1][j - 1];
                    dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) + coins[i - 1][j - 1];
                }else
                {
                    dp0[i][j] = max(dp0[i - 1][j], dp0[i][j - 1]) + coins[i - 1][j - 1];
                    dp1[i][j] = max(max(dp1[i - 1][j], dp1[i][j - 1]) + coins[i - 1][j - 1], max(dp0[i - 1][j], dp0[i][j - 1]));
                    dp2[i][j] = max(max(dp2[i - 1][j], dp2[i][j - 1]) + coins[i - 1][j - 1], max(dp1[i - 1][j], dp1[i][j - 1]));
                }
            }
        }
        return max(dp0.back().back(), max(dp1.back().back(), dp2.back().back()));
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenCoins = {{0 ,1, -1}, {1, -2, 3}, {2, -3, 4}};
    int expectedAnswer = 8;
    assert(solution.maximumAmount(givenCoins) == expectedAnswer);

    givenCoins = {{-7, 12, 12, 13}, {-6, 19, 19, -6}, {9, -2, -10, 16}, {-4, 14, -10, -9}};
    expectedAnswer = 60;
    assert(solution.maximumAmount(givenCoins) == expectedAnswer);

    return 0;
}

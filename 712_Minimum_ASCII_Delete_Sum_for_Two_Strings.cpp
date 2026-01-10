//#712 Minimum ASCII Delete Sum for Two Strings - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= m; i++)
            dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
            for(int j = 1; j <= m; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution solution;
    string givenS1 = "sea";
    string givenS2 = "eat";
    int expectedAnswer = 231;
    assert(solution.minimumDeleteSum(givenS1, givenS2) == expectedAnswer);

    givenS1 = "delete";
    givenS2 = "leet";
    expectedAnswer = 403;
    assert(solution.minimumDeleteSum(givenS1, givenS2) == expectedAnswer);

    return 0;
}

//#64 Minimum Path Sum - https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        for(int i = 1; i < (int)grid[0].size(); i++)
            dp[0][i] += dp[0][i - 1];
        for(int i = 1; i < (int)grid.size(); i++)
            dp[i][0] += dp[i - 1][0];
        for(int i = 1; i < (int)grid.size(); i++)
        {
            for(int j = 1; j < (int)grid[0].size(); j++)
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
        return dp.back().back();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int  expected_answer = 7;
    assert(solution.minPathSum(given_nums) == expected_answer);

    given_nums = {{4, 3, 1}, {5, 7, 9}};
    expected_answer = 17;
    assert(solution.minPathSum(given_nums) == expected_answer);

    return 0;
}

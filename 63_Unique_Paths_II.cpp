//#63 Unique Paths II - https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(n == 1)
        {
            return count(obstacleGrid[0].begin(), obstacleGrid[0].end(), 1) ? 0 : 1;
        }
        else if(m == 1)
        {
            for(int i = 0; i < n; i++)
            {
                if(obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        unsigned int dp[n][m];
        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        else
            return 0;
        for(int i = 1; i < m; i++)
        {
            if(obstacleGrid[0][i] != 1)
                dp[0][i] = dp[0][i - 1];
            else
                dp[0][i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = dp[i - 1][0];
            else
                dp[i][0] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int expected_answer = 2;
    assert(solution.uniquePathsWithObstacles(given_grid) == expected_answer);

    return 0;
}

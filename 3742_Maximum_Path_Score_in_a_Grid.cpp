//#3742 Maximum Path Score in a Grid - https://leetcode.com/problems/maximum-path-score-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(k + 1, - 1)));
        dp[0][0][grid.front().front() == 2 ? 1 : grid.front().front()] = grid.front().front();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int t = 0; t <= k; t++)
                {
                    if(dp[i][j][t] != -1)
                    {
                        if(i + 1 < n)
                        {
                            int cost = grid[i + 1][j] == 0 ? 0 : 1;
                            if(t + cost <= k)
                                dp[i + 1][j][t + cost] = max(dp[i + 1][j][t + cost], dp[i][j][t] + grid[i + 1][j]);
                        }
                        if(j + 1 < m)
                        {
                            int cost = grid[i][j + 1] == 0 ? 0 : 1;
                            if(t + cost <= k)
                                dp[i][j + 1][t + cost] = max(dp[i][j + 1][t + cost], dp[i][j][t] + grid[i][j + 1]);
                        }
                    }
                }
            }
        }
        int result = -1;
        for(int i = 0; i <= k; i++)
        {
            result = max(result, dp.back().back()[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{0, 1}, {2, 0}};
    int givenK = 1;
    int expectedAnswer = 2;
    assert(solution.maxPathScore(givenGrid, givenK) == expectedAnswer);

    givenGrid = {{0, 1} ,{1, 2}};
    givenK = 1;
    expectedAnswer = -1;
    assert(solution.maxPathScore(givenGrid, givenK) == expectedAnswer);

    return 0;
}

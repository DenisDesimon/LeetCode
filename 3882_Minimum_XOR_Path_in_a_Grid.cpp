//#3882 Minimum XOR Path in a Grid - https://leetcode.com/problems/minimum-xor-path-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<bool>> dp(m, vector<bool>(1024, false));
        dp[0][grid.front().front()] = true;
        for(int i = 0; i < n; i++)
        {
            vector<vector<bool>> next(m, vector<bool>(1024, false));
            for(int j = 0; j < m; j++)
            {
                for(int k = 0; k < 1024; k++)
                {
                    if(dp[j][k])
                    {
                        if(i < n - 1)
                            next[j][k ^ grid[i + 1][j]] = true;
                        if(j < m - 1)
                            dp[j + 1][k ^ grid[i][j + 1]] = true;
                    }
                }
            }
            if(i < n - 1)
                dp = move(next);
        }
        for(int k = 0; k < 1024; k++)
        {
            if(dp[m - 1][k])
                return k;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 2}, {3, 4}};
    int expectedAnswer = 6;
    assert(solution.minCost(givenGrid) == expectedAnswer);

    givenGrid = {{6, 7}, {5, 8}};
    expectedAnswer = 9;
    assert(solution.minCost(givenGrid) == expectedAnswer);

    return 0;
}

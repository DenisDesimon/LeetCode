//#3665 Twisted Mirror Path Count - https://leetcode.com/problems/twisted-mirror-path-count/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    int n, m;
    int MOD = 1e9 + 7;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}};
    void update(int i, int j, int move, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int nextI = i + moves[move].first;
        int nextJ = j + moves[move].second;
        while(nextI < n && nextJ < m && grid[nextI][nextJ])
        {
            move = (move + 1) % 2;
            nextI += moves[move].first;
            nextJ += moves[move].second;
        }
        if(nextI < n && nextJ < m)
            dp[nextI][nextJ] = (dp[nextI][nextJ] + dp[i][j]) % MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid.front().size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp.front().front() = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!dp[i][j])
                    continue;
                update(i, j, 0, grid, dp);
                update(i, j, 1, grid, dp);
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int expectedAnswer = 5;
    assert(solution.uniquePaths(givenGrid) == expectedAnswer);

    givenGrid = {{0, 0}, {0, 0}};
    expectedAnswer = 2;
    assert(solution.uniquePaths(givenGrid) == expectedAnswer);


    return 0;
}

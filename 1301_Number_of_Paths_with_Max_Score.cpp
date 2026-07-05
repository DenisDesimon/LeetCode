//#1301 Number of Paths with Max Score - https://leetcode.com/problems/number-of-paths-with-max-score/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, 0}));
        dp.back().back() = {0, 1};
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {1, 1}};
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(!(i == n - 1 && j == n - 1) && board[i][j] != 'X')
                {
                    for(auto &dir : dirs)
                    {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x >= n || y >= n || dp[x][y].first == -1)
                            continue;
                        if(dp[x][y].first > dp[i][j].first)
                            dp[i][j] = dp[x][y];
                        else if(dp[x][y].first == dp[i][j].first)
                            dp[i][j].second = (dp[i][j].second + dp[x][y].second) % MOD;
                    }
                    if(dp[i][j].first != -1)
                        dp[i][j].first += board[i][j] == 'E' ? 0 : board[i][j] - '0';
                }
            }
        }
        return dp.front().front().first == -1 ? vector<int>{0, 0} : vector<int>{dp.front().front().first, dp.front().front().second};
    }
};

int main()
{
    Solution solution;
    vector<string> givenBoard = {"E23", "2X2", "12S"};
    vector<int> expectedAnswer = {7, 1};
    assert(solution.pathsWithMaxScore(givenBoard) == expectedAnswer);

    givenBoard = {"E12", "1X1", "21S"};
    expectedAnswer = {4, 2};
    assert(solution.pathsWithMaxScore(givenBoard) == expectedAnswer);

    return 0;
}

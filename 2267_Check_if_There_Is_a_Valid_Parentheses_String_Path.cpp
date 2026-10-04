//#2267 Check if There Is a Valid Parentheses String Path - https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
#include <iostream>
#include <cassert>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int len = n + m - 1;
        if(len % 2 || grid.front().front() == ')' || grid.back().back() == '(')
            return false;
        vector<vector<bitset<201>>> dp(n, vector<bitset<201>>(m));
        dp.front().front().set(1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i + 1 < n)
                {
                    if(grid[i + 1][j] == '(')
                        dp[i + 1][j] |= dp[i][j] << 1;
                    else
                        dp[i + 1][j] |= dp[i][j] >> 1;
                }
                if(j + 1 < m)
                {
                    if(grid[i][j + 1] == '(')
                        dp[i][j + 1] |= dp[i][j] << 1;
                    else
                        dp[i][j + 1] |= dp[i][j] >> 1;
                }
            }
        }
        return dp.back().back().test(0);
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> givenGrid = {{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}};
    bool expectedAnswer = true;
    assert(solution.hasValidPath(givenGrid) == expectedAnswer);

    givenGrid = {{')', ')'}, {'(', '('}};
    expectedAnswer = false;
    assert(solution.hasValidPath(givenGrid) == expectedAnswer);

    return 0;
}

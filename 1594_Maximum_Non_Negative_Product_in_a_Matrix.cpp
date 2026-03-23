//#1594 Maximum Non Negative Product in a Matrix - https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int mod = 1e9 + 7;
        vector<vector<long long>> dpMax(n, vector<long long>(m, LLONG_MIN));
        vector<vector<long long>> dpMin(n, vector<long long>(m, LLONG_MAX));
        dpMax.front().front() = grid.front().front();
        dpMin.front().front() = grid.front().front();
        for(int i = 1; i < n; i++)
        {
            dpMax[i][0] = dpMin[i][0] = dpMax[i - 1][0] * grid[i][0];
        }
        for(int j = 1; j < m; j++)
        {
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j - 1] * grid[0][j];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(grid[i][j] >= 0)
                {
                    dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
                    dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
                }
                else
                {
                    dpMax[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
                    dpMin[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
                }
            }
        }
        return dpMax.back().back() < 0 ? -1 : dpMax.back().back() % mod;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{-1, -2, -3} ,{-2, -3, -3}, {-3, -3, -2}};
    int expectedAnswer = -1;
    assert(solution.maxProductPath(givenMatrix) == expectedAnswer);

    givenMatrix = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
    expectedAnswer = 8;
    assert(solution.maxProductPath(givenMatrix) == expectedAnswer);

    return 0;
}

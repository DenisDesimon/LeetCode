//#3197 Find the Minimum Area to Cover All Ones II - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<vector<int>> rotate(vector<vector<int>> &grid){
        vector<vector<int>> rotatedGrid(grid.front().size(), vector<int>(grid.size()));
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(int j = 0; j < (int)grid.front().size(); j++)
                rotatedGrid[grid.front().size() - 1 - j][i] = grid[i][j];
        }
        return rotatedGrid;
    }
    int minArea(vector<vector<int>> &grid, int startRow, int endRow, int left, int right){
        int leftTopRow = grid.size(), leftTopCol = grid.front().size();
        int rightBotRow = 0, rightBotCol = 0;
        for(int i = startRow; i <= endRow; i++)
        {
            for(int j = left; j <= right; j++)
            {
                if(grid[i][j])
                {
                    leftTopRow = min(leftTopRow, i);
                    leftTopCol = min(leftTopCol, j);
                    rightBotRow = max(rightBotRow, i);
                    rightBotCol = max(rightBotCol, j);
                }
            }
        }
        return leftTopRow > rightBotRow ? INT_MAX / 3 : (rightBotRow - leftTopRow + 1) * (rightBotCol - leftTopCol + 1);
    }
    int solve(vector<vector<int>> &grid){
        int n = grid.size(), m = grid.front().size();
        int result = n * m;
        for(int i = 0; i + 1 < n; i++)
        {
            for(int j = 0; j + 1 < m; j++)
            {
                result = min(result, minArea(grid, 0, i, 0, m - 1) + minArea(grid, i + 1, n - 1, 0, j) +
                             minArea(grid, i + 1, n - 1, j + 1, m - 1));

                result = min(result, minArea(grid, 0, i, 0, j) + minArea(grid, 0, i, j + 1, m - 1) +
                             minArea(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for(int i = 0; i + 2 < n; i++)
        {
            for(int j = i + 1; j + 1 < n; j++)
            {
                result = min(result, minArea(grid, 0, i, 0, m - 1) + minArea(grid, i + 1, j, 0, m - 1) +
                             minArea(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return result;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        auto rotatedGrid = rotate(grid);
        return min(solve(grid), solve(rotatedGrid));
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 0, 1}, {1, 1, 1}};
    int expectedAnswer = 5;
    assert(solution.minimumSum(givenGrid) == expectedAnswer);

    givenGrid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    expectedAnswer = 3;
    assert(solution.minimumSum(givenGrid) == expectedAnswer);

    return 0;
}

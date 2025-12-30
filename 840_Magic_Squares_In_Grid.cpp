//840 Magic Squares In Grid - https://leetcode.com/problems/magic-squares-in-grid/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    bool isMagic(int row, int col, vector<vector<int>>& grid)
    {
        bool unique[10] = {false};
        for(int i = row; i < row + 3; i++)
        {
            for(int j = col; j < col + 3; j++)
            {
                if(grid[i][j] < 1 || grid[i][j] > 9)
                    return false;
                if(unique[grid[i][j]])
                    return false;
                unique[grid[i][j]] = true;
            }
        }
        int diagonal = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        if(diagonal != grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col])
            return false;
        if(diagonal != grid[row][col] + grid[row][col + 1] + grid[row][col + 2])
            return false;
        if(diagonal != grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2])
            return false;
        if(diagonal != grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2])
            return false;
        if(diagonal != grid[row][col] + grid[row + 1][col] + grid[row + 2][col])
            return false;
        if(diagonal != grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1])
            return false;
        if(diagonal != grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2])
            return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i + 2 < (int)grid.size(); i++)
        {
            for(int j = 0; j + 2 < (int)grid[i].size(); j++)
            {
                if(isMagic(i, j, grid))
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid  = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    int expectedAnswer = 1;
    assert(solution.numMagicSquaresInside(givenGrid) == expectedAnswer);

    givenGrid = {{8}};
    expectedAnswer = 0;
    assert(solution.numMagicSquaresInside(givenGrid) == expectedAnswer);

    return 0;
}

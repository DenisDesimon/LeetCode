//#200 Number of Islands - https://leetcode.com/problems/number-of-islands/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool if_Island(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] == '0')
            return true;
        grid[row][col] = '0';
        bool left = true, right = true, bott = true, top = true;
        if(row > 0)
            top = if_Island(grid, row - 1, col);
        if(row < (int)grid.size() - 1)
            bott = if_Island(grid, row + 1, col);
        if(col > 0)
            left = if_Island(grid, row, col - 1);
        if(col < (int)grid[0].size() - 1)
            right = if_Island(grid, row, col + 1);
        return left && right && top && bott;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(int j = 0; j < (int)grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                    result += if_Island(grid, i, j);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_grid = {{'1','1','1','1','1','1','1'},
                                       {'0','0','0','0','0','0','1'},
                                       {'1','1','1','1','1','0','1'},
                                       {'1','0','0','0','1','0','1'},
                                       {'1','0','1','0','1','0','1'},
                                       {'1','0','1','1','1','0','1'},
                                       {'1','1','1','1','1','1','1'}};
    int expected_answer = 1;
    assert(solution.numIslands(given_grid) == expected_answer);

    given_grid = {{'1', '1', '0', '0', '0'},
                  {'1', '1', '0', '0', '0'},
                  {'0', '0', '1', '0', '0'},
                  {'0', '0', '0', '1', '1'}};
    expected_answer = 3;
    assert(solution.numIslands(given_grid) == expected_answer);

    return 0;
}

//#1254 Number of Closed Islands - https://leetcode.com/problems/number-of-closed-islands/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool checkIsland(vector<vector<int>>& grid, int cur_i, int cur_j){
        if(grid[cur_i][cur_j])
            return true;
        grid[cur_i][cur_j] = 1;
        bool left = false, right = false, top = false, bot = false;
        if(cur_j > 0)
            left = checkIsland(grid, cur_i, cur_j - 1);
        if(cur_j < (int)grid[0].size() - 1)
            right = checkIsland(grid, cur_i, cur_j + 1);
        if(cur_i > 0)
            top = checkIsland(grid, cur_i - 1, cur_j);
        if(cur_i < (int)grid.size() - 1)
            bot = checkIsland(grid, cur_i + 1, cur_j);
        return left && right && top && bot;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 1; i < (int)grid.size(); i++)
        {
            for(int j = 1; j < (int)grid[0].size(); j++)
            {
                if(!grid[i][j])
                    result += checkIsland(grid, i, j);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
    int expected_answer = 1;
    assert(solution.closedIsland(given_grid) == expected_answer);

    given_grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0},
                  {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
    expected_answer = 2;
    assert(solution.closedIsland(given_grid) == expected_answer);

    return 0;
}

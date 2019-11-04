//#1219 Path with Maximum Gold - https://leetcode.com/problems/path-with-maximum-gold/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    int back_track(vector<vector<int>>& grid, int sum, int i, int j){
        sum += grid[i][j];
        int swap = grid[i][j];
        grid[i][j] = 0;
        int up = 0, down = 0, left = 0, right = 0;
        if(i != 0 && grid[i - 1][j] != 0)
            up = back_track(grid, 0, i - 1, j);
        if(i != (int)grid.size() - 1 && grid[i + 1][j] != 0)
            down = back_track(grid, 0, i + 1, j);
        if(j != 0 && grid[i][j - 1] != 0)
            left = back_track(grid, 0, i, j - 1);
        if(j != (int)grid[0].size() - 1 && grid[i][j + 1] != 0)
            right = back_track(grid, 0, i, j + 1);
        grid[i][j] = swap;
        return sum + max({up, down, left, right});

    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        int sum;
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(int j = 0; j < (int)grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                    continue;
                sum = back_track(grid, 0, i, j);
                result = max(result, sum);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    int expected_answer = 28;
    assert(solution.getMaximumGold(given_grid) == expected_answer);

    given_grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    expected_answer = 24;
    assert(solution.getMaximumGold(given_grid) == expected_answer);

    return 0;
}

//#1260 Shift 2D Grid - https://leetcode.com/problems/shift-2d-grid/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        k %= n * m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int abs_pos = (i * m + j + k) % (n * m);
                result[abs_pos / m][abs_pos % m] = grid[i][j];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 2, 3},
                                      {4, 5, 6},
                                      {7, 8, 9}};
    int given_k = 44;
    vector<vector<int>> expected_answer = {{2, 3, 4},
                                           {5, 6, 7},
                                           {8, 9, 1}};
    assert(solution.shiftGrid(given_grid, given_k) == expected_answer);

    given_grid = {{3, 8, 1, 9},
                  {19, 7, 2, 5},
                  {4, 6, 11, 10},
                  {12, 0, 21, 13}};
    given_k = 4;
    expected_answer = {{12, 0, 21, 13},
                       {3, 8, 1, 9},
                       {19, 7, 2, 5},
                       {4, 6, 11, 10}};
    assert(solution.shiftGrid(given_grid, given_k) == expected_answer);


    return 0;
}

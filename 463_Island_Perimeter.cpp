//#463 Island Perimeter - https://leetcode.com/problems/island-perimeter/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(i == 0 || grid[i - 1][j] == 0)
                        result++;
                    if(i == n - 1 || grid[i + 1][j] == 0)
                        result++;
                    if(j == 0 || grid[i][j - 1] == 0)
                        result++;
                    if(j == m - 1 || grid[i][j + 1] == 0)
                        result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1}};
    int expected_answer = 4;
    assert(solution.islandPerimeter(given_grid) == expected_answer);

    given_grid = {{0, 1, 0, 0},
                  {1, 1, 1, 0},
                  {0, 1, 0, 0},
                  {1, 1, 0, 0}};
    expected_answer = 16;
    assert(solution.islandPerimeter(given_grid) == expected_answer);

    return 0;
}

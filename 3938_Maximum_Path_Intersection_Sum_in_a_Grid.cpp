//#3938 Maximum Path Intersection Sum in a Grid - https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int result = INT_MIN;
        int n = grid.size();
        int m = grid.front().size();
        for(int j = 0; j < m; j++)
        {
            int prev = grid[0][j];
            for(int i = 1; i < n; i++)
            {
                result = max(prev + grid[i][j], result);
                if(i > 0 && j > 0 && i < n - 1 && j < m - 1)
                    result = max(result, grid[i][j]);
                prev = max(grid[i][j], prev + grid[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            int prev = grid[i][0];
            for(int j = 1; j < m; j++)
            {
                result = max(result, prev + grid[i][j]);
                if(i > 0 && j > 0 && i < n - 1 && j < m - 1)
                    result = max(result, grid[i][j]);
                prev = max(grid[i][j], prev + grid[i][j]);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid  = {{4, -2, -3}, {-1, -3, -1}, {-4, 2, -1}};
    int expectedAnswer = 3;
    assert(solution.maxScore(givenGrid) == expectedAnswer);

    givenGrid  = {{-15, -16}, {-7, 12}};
    expectedAnswer = 5;
    assert(solution.maxScore(givenGrid) == expectedAnswer);

    return 0;
}

//#1351 Count Negative Numbers in a Sorted Matrix - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = grid.size() - 1; i >= 0; i--)
        {
            for(int j = grid[0].size() - 1; j >= 0; j--)
            {
                if(grid[i][j] < 0)
                    result++;
                else
                    break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int expected_answer = 8;
    assert(solution.countNegatives(given_grid) == expected_answer);

    given_grid = {{3, 2}, {1, 0}};
    expected_answer = 0;
    assert(solution.countNegatives(given_grid) == expected_answer);

    return 0;
}

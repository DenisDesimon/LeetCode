//#64 Minimum Path Sum - https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size_y = (int)grid.size();
        int size_x = (int)grid[0].size();
        int sum[size_y][size_x];
        for (int y = 0; y < size_y; y++)
        {
            for(int x = 0; x < size_x; x++)
            {
                if(y == 0 && x > 0)
                    sum[y][x] = sum[y][x - 1] + grid[y][x];
                else if(y > 0 && x == 0)
                    sum[y][x] = sum[y - 1][x] + grid[y][x];
                else if(y == 0 && x == 0)
                    sum[y][x] = grid[y][x];
                else
                sum[y][x] = min(sum[y][x - 1], sum[y - 1][x]) + grid[y][x];
            }
        }
        return sum[size_y - 1][size_x - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int  expected_answer = 7;
    assert(solution.minPathSum(given_nums) == expected_answer);

    given_nums = {{4, 3, 1}, {5, 7, 9}};
    expected_answer = 17;
    assert(solution.minPathSum(given_nums) == expected_answer);

    return 0;
}

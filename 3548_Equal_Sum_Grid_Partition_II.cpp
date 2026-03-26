//#3548 Equal Sum Grid Partition II - https://leetcode.com/problems/equal-sum-grid-partition-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> rotate(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> result(m, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < (int)grid.front().size(); j++)
            {
                result[m - 1 - j][i] = grid[i][j];
            }
        }
        return result;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        for(auto &row : grid)
        {
            for(auto &col : row)
                totalSum += col;
        }
        for(int rotations = 0; rotations < 4; rotations++)
        {
            int n = grid.size();
            int m = grid.front().size();
            long long curSum = 0;
            unordered_set<long long> discounts;
            if(n < 2)
            {
                grid = rotate(grid);
                continue;
            }
            if(m == 1)
            {
                for(int i = 0; i < n - 1; i++)
                {
                    curSum += grid[i][0];
                    long long target = curSum * 2 - totalSum;
                    if(target == 0 || target == grid[0][0] || target == grid[i][0])
                        return true;
                }
                grid = rotate(grid);
                continue;
            }
            for(int i = 0; i < n - 1; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    curSum += grid[i][j];
                    discounts.insert(grid[i][j]);
                }
                long long target = curSum * 2 - totalSum;
                if(i == 0)
                {
                    if(target == 0 || target == grid[0][0] || target == grid[0][m - 1])
                        return true;
                    continue;
                }
                if(target == 0 || discounts.count(target))
                    return true;
            }
            grid = rotate(grid);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{1, 2, 4}, {2, 3, 5}};
    bool expectedAnswer = false;
    assert(solution.canPartitionGrid(givenMatrix) == expectedAnswer);

    givenMatrix = {{1, 2}, {3, 4}};
    expectedAnswer = true;
    assert(solution.canPartitionGrid(givenMatrix) == expectedAnswer);

    return 0;
}

//#3546 Equal Sum Grid Partition I - https://leetcode.com/problems/equal-sum-grid-partition-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        long long totalSum = 0;
        for(auto &row : grid)
        {
            for(auto &col : row)
                totalSum += col;
        }
        if(totalSum % 2)
            return false;
        long long sumVert = 0, sumHor = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                sumHor += grid[i][j];
                if(sumHor == totalSum / 2)
                    return true;
                else if(sumHor > totalSum / 2)
                    break;
            }
        }
        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                sumVert += grid[i][j];
                if(sumVert == totalSum / 2)
                    return true;
                else if(sumVert > totalSum / 2)
                    break;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{1, 4}, {2, 3}};
    bool expectedAnswer = true;
    assert(solution.canPartitionGrid(givenMatrix) == expectedAnswer);

    givenMatrix = {{1, 3}, {2, 4}};
    expectedAnswer = false;
    assert(solution.canPartitionGrid(givenMatrix) == expectedAnswer);

    return 0;
}

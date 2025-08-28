//#3446 Sort Matrix by Diagonals - https://leetcode.com/problems/sort-matrix-by-diagonals/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int diagStart = 0; diagStart < (int)grid.size() * 2 - 1; diagStart++)
        {
            int i = diagStart < (int)grid.size() ? grid.size() - diagStart - 1 : 0;
            int j = diagStart < (int)grid.size() ? 0 : diagStart - grid.size() + 1;
            vector<int> diagNums;
            while(i < (int)grid.size() && j < (int)grid.size())
                diagNums.push_back(grid[i++][j++]);
            if(diagStart >= (int)grid.size())
                sort(diagNums.begin(), diagNums.end(), greater<int>());
            else
                sort(diagNums.begin(), diagNums.end());
            int t = 0;
            i--, j--;
            while(i >= 0 && j >= 0)
                grid[i--][j--] = diagNums[t++];
        }
        return grid;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> expectedAnswer = {{8, 2, 3}, {9, 6, 7}, {4, 5, 1}};
    assert(solution.sortMatrix(givenGrid) == expectedAnswer);

    givenGrid = {{0, 1}, {1, 2}};
    expectedAnswer = {{2, 1}, {1, 0}};
    assert(solution.sortMatrix(givenGrid) == expectedAnswer);

    return 0;
}

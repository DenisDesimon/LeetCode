//#3195 Find the Minimum Area to Cover All Ones I - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        pair<int, int> leftTop = {INT_MAX, INT_MAX}, rightBott = {-1, -1};
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(int j = 0; j < (int)grid.front().size(); j++)
            {
                if(grid[i][j])
                {
                    leftTop = {min(leftTop.first, i), min(leftTop.second, j)};
                    rightBott = {max(rightBott.first, i), max(rightBott.second, j)};
                }
            }
        }
        return (rightBott.first - leftTop.first + 1) * (rightBott.second - leftTop.second + 1);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 0}, {1, 0}};
    int expectedAnswer = 2;
    assert(solution.minimumArea(givenGrid) == expectedAnswer);

    givenGrid = {{0, 1, 0}, {1, 0, 1}};
    expectedAnswer = 6;
    assert(solution.minimumArea(givenGrid) == expectedAnswer);

    return 0;
}

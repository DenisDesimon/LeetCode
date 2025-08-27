//#3459 Length of Longest V-Shaped Diagonal Segment - https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    vector<int> diag = {1, 3, 0, 2};
    int memo[501][501][4][2];
    int countLength(int i, int j, bool isV, int direction, vector<vector<int>>& grid, int target){
           if(i >= (int)grid.size() || j >= (int)grid.front().size() || i < 0 || j < 0 || grid[i][j] != target)
               return 0;
           if(memo[i][j][direction][isV] != -1)
               return memo[i][j][direction][isV];
           int result = 0;
           result = max(result, countLength(i + directions[direction][0], j + directions[direction][1], isV, direction, grid, 2 - target) + 1);
           if(!isV)
               result = max(result, countLength(i + directions[diag[direction]][0], j + directions[diag[direction]][1], true, diag[direction], grid, 2 - target) + 1);
           memo[i][j][direction][isV] = result;
           return result;
       }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int result = 0;
        memset(memo, -1, sizeof(memo));
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(int j = 0; j < (int)grid.front().size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int d = 0; d < 4; d++)
                        result = max(result, countLength(i + directions[d][0], j + directions[d][1], false, d, grid, 2) + 1);
                }
            }
        }
        return result;
    }
};



int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{2, 2, 1, 2, 2},{2, 0, 2, 2, 0},{2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    int expectedAnswer = 5;
    assert(solution.lenOfVDiagonal(givenGrid) == expectedAnswer);

    givenGrid = {{2, 2, 2, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    expectedAnswer = 4;
    assert(solution.lenOfVDiagonal(givenGrid) == expectedAnswer);

    return 0;
}

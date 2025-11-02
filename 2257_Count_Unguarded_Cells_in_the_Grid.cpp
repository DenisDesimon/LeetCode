//#2257 Count Unguarded Cells in the Grid - https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    const int GUARDED = 1;
    const int  WALLORGUARD = 2;
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        for(auto &wall : walls)
            grid[wall[0]][wall[1]] = WALLORGUARD;
        for(auto &guard : guards)
            grid[guard[0]][guard[1]] = WALLORGUARD;
        for(auto &guard : guards)
        {
            for(int i = guard[0] - 1; i >= 0; i--)
            {
                if(grid[i][guard[1]] == WALLORGUARD)
                    break;
                grid[i][guard[1]] = GUARDED;
            }
            for(int i = guard[0] + 1; i < m; i++)
            {
                if(grid[i][guard[1]] == WALLORGUARD)
                    break;
                grid[i][guard[1]] = GUARDED;
            }
            for(int i = guard[1] - 1; i >= 0; i--)
            {
                if(grid[guard[0]][i] == WALLORGUARD)
                    break;
                grid[guard[0]][i] = GUARDED;
            }
            for(int i = guard[1] + 1; i < n; i++)
            {
                if(grid[guard[0]][i] == WALLORGUARD)
                    break;
                grid[guard[0]][i] = GUARDED;
            }
        }
        int result = 0;
        for(auto &row : grid)
        {
            for(auto &col : row)
                result += col ? 0 : 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenM = 4, givenN = 6;
    vector<vector<int>> givenGuards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> givenWalls = {{0, 1}, {2, 2}, {1, 4}};
    int expectedAnswer = 7;
    assert(solution.countUnguarded(givenM, givenN, givenGuards, givenWalls) == expectedAnswer);

    givenM = 3, givenN = 3;
    givenGuards = {{1, 1}};
    givenWalls = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    expectedAnswer = 4;
    assert(solution.countUnguarded(givenM, givenN, givenGuards, givenWalls) == expectedAnswer);

    return 0;
}

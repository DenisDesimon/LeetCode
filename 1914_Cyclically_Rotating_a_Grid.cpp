//#1914 Cyclically Rotating a Grid - https://leetcode.com/problems/cyclically-rotating-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        int layerCount = min(n / 2, m / 2);
        for(int curLayer = 0; curLayer < layerCount; curLayer++)
        {
            vector<int> r, c, val;
            for(int i = curLayer; i < n - curLayer - 1; i++)
            {
                r.push_back(i);
                c.push_back(curLayer);
                val.push_back(grid[i][curLayer]);
            }
            for(int j = curLayer; j < m - curLayer - 1; j++)
            {
                r.push_back(n - curLayer - 1);
                c.push_back(j);
                val.push_back(grid[n - curLayer - 1][j]);
            }
            for(int i = n - 1 - curLayer; i > curLayer; i--)
            {
                r.push_back(i);
                c.push_back(m - curLayer - 1);
                val.push_back(grid[i][m - curLayer - 1]);
            }
            for(int j = m - 1 - curLayer; j > curLayer; j--)
            {
                r.push_back(curLayer);
                c.push_back(j);
                val.push_back(grid[curLayer][j]);
            }
            int total = val.size();
            int rotations = k % total;
            for(int i = 0; i < total; i++)
            {
                grid[r[i]][c[i]] = val[(i - rotations + total) % total];
            }
        }
        return grid;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{40,10}, {30, 20}};
    int givenK = 1;
    vector<vector<int>> expectedAnswer = {{10, 20}, {40, 30}};
    assert(solution.rotateGrid(givenGrid, givenK) == expectedAnswer);

    givenGrid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    givenK = 2;
    expectedAnswer = {{3, 4, 8, 12}, {2, 11, 10, 16}, {1, 7, 6, 15}, {5, 9, 13, 14}};
    assert(solution.rotateGrid(givenGrid, givenK) == expectedAnswer);

    return 0;
}

//#1559 Detect Cycles in 2D Grid - https://leetcode.com/problems/detect-cycles-in-2d-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    pair<int, int> directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isCycle(int x, int y, int prev, char value, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(x >= (int)grid.size() || y >= (int)grid.front().size() || x < 0 || y < 0 || grid[x][y] != value)
            return false;
        if(visited[x][y])
            return true;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++)
        {
            if(i == prev)
                continue;
            if(isCycle(x + directions[i].first, y + directions[i].second, (i + 2) % 4, value, grid, visited))
                return true;
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<bool>> visited(n, vector<bool> (m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && isCycle(i, j, -1, grid[i][j], grid, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> givenGrid = {{'a', 'a', 'a', 'a'},{'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}};
    bool expectedAnswer = true;
    assert(solution.containsCycle(givenGrid) == expectedAnswer);

    givenGrid = {{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
    expectedAnswer = false;
    assert(solution.containsCycle(givenGrid) == expectedAnswer);

    return 0;
}

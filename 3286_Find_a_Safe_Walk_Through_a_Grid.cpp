//#3286 Find a Safe Walk Through a Grid - https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<bool>> visited(n, vector<bool> (m));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cells;
        cells.push({grid[0][0], 0});
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!cells.empty())
        {
            int x = cells.top().second / m;
            int y = cells.top().second % m;
            int healthUsed = cells.top().first;
            cells.pop();
            if(x == n - 1 && y == m - 1)
                return true;
            if(visited[x][y])
                continue;
            visited[x][y] = true;
            for(auto &dir : dirs)
            {
                int nextX = x + dir[0];
                int nextY = y + dir[1];
                if(nextX < n && nextY < m && nextX >= 0 && nextY >= 0 && healthUsed + grid[nextX][nextY] < health && !visited[nextX][nextY])
                {
                    cells.push({healthUsed + grid[nextX][nextY], nextX * m + nextY});
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGird = {{1, 1 ,1}, {1, 0, 1}, {1, 1, 1}};
    int givenHealth = 5;
    bool expectedAnswer = true;
    assert(solution.findSafeWalk(givenGird, givenHealth) == expectedAnswer);

    givenGird = {{1, 1, 1, 1}};
    givenHealth = 4;
    expectedAnswer = false;
    assert(solution.findSafeWalk(givenGird, givenHealth) == expectedAnswer);

    return 0;
}

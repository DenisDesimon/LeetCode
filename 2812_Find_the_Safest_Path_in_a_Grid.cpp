//#2812 Find the Safest Path in a Grid - https://leetcode.com/problems/find-the-safest-path-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid.front().front() || grid.back().back())
            return 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size();
        queue<pair<int, int>> cells;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                    cells.push({i, j});
            }
        }

        while(!cells.empty())
        {
            int i = cells.front().first;
            int j = cells.front().second;
            cells.pop();
            for(auto &dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];
                if(min(x, y) >= 0 && max(x, y) < n && grid[x][y] == 0)
                {
                    grid[x][y] = grid[i][j] + 1;
                    cells.push({x, y});
                }
            }
        }
        int result = grid[0][0];
        priority_queue<pair<int, int>> pq;
        pq.push({grid[0][0], 0});
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int i = pq.top().second / n;
            int j = pq.top().second % n;
            pq.pop();
            result = min(result, dist);
            if(i == n - 1 && j == n - 1)
                return result - 1;
            for(auto &dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];
                if(min(x, y) >= 0 && max(x, y) < n && grid[x][y] > 0)
                {
                    pq.push({grid[x][y], x * n + y});
                    grid[x][y] = 0;
                }
            }
        }
        return result - 1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    int expectedAnswer = 0;
    assert(solution.maximumSafenessFactor(givenGrid) == expectedAnswer);

    givenGrid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    expectedAnswer = 2;
    assert(solution.maximumSafenessFactor(givenGrid) == expectedAnswer);

    return 0;
}

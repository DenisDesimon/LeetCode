//#778 Swim in Rising Water - https://leetcode.com/problems/swim-in-rising-water/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto comp = [&](pair<int, pair<int, int>> left, pair<int, pair<int, int>> right){return left.first >= right.first;};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> timeRowCol(comp);
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size();
        int shortestTime = 0;
        vector<vector<int>> visited(n, vector<int>(n));
        timeRowCol.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        while(!timeRowCol.empty())
        {
            int time = timeRowCol.top().first;
            int row = timeRowCol.top().second.first;
            int col = timeRowCol.top().second.second;
            timeRowCol.pop();
            shortestTime = max(time, shortestTime);
            if(row == n - 1 && col == n - 1)
                return shortestTime;
            for(auto &dir : directions)
            {
                int nextR = row + dir[0];
                int nextC = col + dir[1];
                if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && !visited[nextR][nextC])
                {
                    visited[nextR][nextC] = true;
                    timeRowCol.push({grid[nextR][nextC], {nextR, nextC}});
                }
            }
        }
        return shortestTime;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{0, 2}, {1, 3}};
    int expectedAnswer = 3;
    assert(solution.swimInWater(givenGrid) == expectedAnswer);

    givenGrid = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    expectedAnswer = 16;
    assert(solution.swimInWater(givenGrid) == expectedAnswer);

    return 0;
}

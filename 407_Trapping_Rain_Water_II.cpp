//#407 Trapping Rain Water II - https://leetcode.com/problems/trapping-rain-water-ii/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap.front().size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(m));
        auto comp = [&](pair<int, pair<int, int>> left, pair<int, pair<int, int>> right){return left.first >= right.first;};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> minHeightRowCol(comp);
        for(int i = 0; i < m; i++)
        {
            minHeightRowCol.push({heightMap.front()[i], {0, i}});
            minHeightRowCol.push({heightMap.back()[i], {n - 1, i}});
            visited[0][i] = true, visited[n - 1][i] = true;
        }
        for(int i = 0; i < n; i++)
        {
            minHeightRowCol.push({heightMap[i].front(), {i, 0}});
            minHeightRowCol.push({heightMap[i].back(), {i, m - 1}});
            visited[i][0] = true, visited[i][m - 1] = true;
        }
        int result = 0;
        while(!minHeightRowCol.empty())
        {
            int height = minHeightRowCol.top().first, row = minHeightRowCol.top().second.first, col = minHeightRowCol.top().second.second;
            minHeightRowCol.pop();
            for(auto dir : directions)
            {
                int nextR = row + dir[0];
                int nextC = col + dir[1];
                if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && !visited[nextR][nextC])
                {
                    visited[nextR][nextC] = true;
                    if(height > heightMap[nextR][nextC])
                        result += height - heightMap[nextR][nextC];
                    minHeightRowCol.push({max(height, heightMap[nextR][nextC]), {nextR, nextC}});
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenHeightMap = {{1, 4, 3 ,1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    int expectedAnswer = 4;
    assert(solution.trapRainWater(givenHeightMap) == expectedAnswer);

    givenHeightMap = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3 ,3, 3, 3, 3}};
    expectedAnswer = 10;
    assert(solution.trapRainWater(givenHeightMap) == expectedAnswer);

    return 0;
}

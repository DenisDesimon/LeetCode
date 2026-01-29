//#3651 Minimum Cost Path with Teleportations - https://leetcode.com/problems/minimum-cost-path-with-teleportations/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> costToEnd(n, vector<int> (m, INT_MAX));
        costToEnd[n - 1][m - 1] = 0;
        vector<pair<int, int>> points;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(), [&] (pair<int, int> &left, pair<int, int> &right){return grid[left.first][left.second] <
                    grid[right.first][right.second];});
        for(int t = 0; t <= k; t++)
        {
            int minCost = INT_MAX;
            for(int right = 0, left = 0; t && right < (int)points.size(); right++)
            {
                minCost = min(minCost, costToEnd[points[right].first][points[right].second]);
                if(right + 1 < (int)points.size() && grid[points[right].first][points[right].second] ==
                        grid[points[right + 1].first][points[right + 1].second])
                    continue;
                for(int i = left; i <= right; i++)
                    costToEnd[points[i].first][points[i].second] = minCost;
                left = right + 1;
            }
            for(int i = n - 1; i >= 0; i--)
            {
                for(int j = m - 1; j >= 0; j--)
                {
                    if(i < n - 1)
                        costToEnd[i][j] = min(costToEnd[i][j], costToEnd[i + 1][j] + grid[i + 1][j]);
                    if(j < m - 1)
                        costToEnd[i][j] = min(costToEnd[i][j], costToEnd[i][j + 1] + grid[i][j + 1]);
                }
            }
        }
        return costToEnd.front().front();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
    int givenK = 2;
    int expected_answer = 7;
    assert(solution.minCost(givenGrid, givenK) == expected_answer);

    givenGrid = {{1, 2}, {2, 3}, {3, 4}};
    givenK = 1;
    expected_answer = 9;
    assert(solution.minCost(givenGrid, givenK) == expected_answer);


    return 0;
}

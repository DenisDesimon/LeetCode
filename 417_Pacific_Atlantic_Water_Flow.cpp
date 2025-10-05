//#417 Pacific Atlantic Water Flow - https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col){
        for(auto &dir: directions)
        {
            int nextR = row + dir[0];
            int nextC = col + dir[1];
            if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && !visited[nextR][nextC])
            {
                if(heights[nextR][nextC] >= heights[row][col])
                {
                    visited[nextR][nextC] = true;
                    dfs(heights, visited, nextR, nextC);
                }
            }

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        n = heights.size(), m = heights.front().size();
        vector<vector<bool>> pacific(n, vector<bool>(m));
        vector<vector<bool>> atlantic(n, vector<bool>(m));
        for(int i = 0; i < m; i++)
        {
            pacific[0][i] = true;
            dfs(heights, pacific, 0, i);
            atlantic[n - 1][i] = true;
            dfs(heights, atlantic, n - 1, i);
        }
        for(int i = 0; i < n; i++)
        {
            pacific[i][0] = true;
            dfs(heights, pacific, i, 0);
            atlantic[i][m - 1] = true;
            dfs(heights, atlantic, i, m - 1);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(atlantic[i][j] && pacific[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenHeights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> expectedAnswer = {{0, 4}, {1, 3}, {1 ,4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
    assert(solution.pacificAtlantic(givenHeights) == expectedAnswer);

    givenHeights = {{1}};
    expectedAnswer = {{0, 0}};
    assert(solution.pacificAtlantic(givenHeights) == expectedAnswer);

    return 0;
}

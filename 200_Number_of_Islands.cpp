//#200 Number of Islands - https://leetcode.com/problems/number-of-islands/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int n, m;
    void mark_visit(int cur_x, int cur_y, vector<vector<int>>& vert, vector<vector<int>>& hor, vector<vector<bool>>& visited)
    {
        if(visited[cur_y][cur_x])
            return;
        visited[cur_y][cur_x] = true;
        if(cur_x + 1 < m && hor[cur_y][cur_x + 1] > 0)
            mark_visit(cur_x + 1, cur_y, vert, hor, visited);
        if(cur_x - 1 >= 0 && hor[cur_y][cur_x - 1] > 0)
            mark_visit(cur_x - 1, cur_y, vert, hor, visited);
        if(cur_y + 1 < n && vert[cur_y + 1][cur_x] > 0)
            mark_visit(cur_x, cur_y + 1, vert, hor, visited);
        if(cur_y - 1 >= 0 && vert[cur_y - 1][cur_x] > 0)
            mark_visit(cur_x, cur_y - 1, vert, hor, visited);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.empty())
            return result;
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vert(n, vector<int>(m, 0)), hor;
        hor = vert;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
                    vert[i][j] = i == 0 ? 1 : vert[i - 1][j] + 1;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j])
                    continue;
                if(hor[i][j] == 1 && vert[i][j] == 1)
                {
                    mark_visit(j, i, vert, hor, visited);
                    result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_nums = {{'1','1','1','1','1','1','1'},
                                       {'0','0','0','0','0','0','1'},
                                       {'1','1','1','1','1','0','1'},
                                       {'1','0','0','0','1','0','1'},
                                       {'1','0','1','0','1','0','1'},
                                       {'1','0','1','1','1','0','1'},
                                       {'1','1','1','1','1','1','1'}};
    int expected_answer = 1;
    assert(solution.numIslands(given_nums) == expected_answer);

    return 0;
}

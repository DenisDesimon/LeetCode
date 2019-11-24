//#1267 Count Servers that Communicate - https://leetcode.com/problems/count-servers-that-communicate/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        vector<int> hor(n, 0);
        vector<int> vert(m, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    hor[i]++;
                    vert[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] && (hor[i] > 1 || vert[j] > 1))
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{0, 0, 1, 0, 1},
                                      {0, 1, 0, 1, 0},
                                      {0, 1, 1, 1, 0},
                                      {1, 0, 0, 1, 1},
                                      {0, 0, 1, 1, 0}};
    int expected_answer = 12;
    assert(solution.countServers(given_grid) == expected_answer);

    given_grid = {{1, 0}, {0, 1}};
    expected_answer = 0;
    assert(solution.countServers(given_grid) == expected_answer);

    return 0;
}

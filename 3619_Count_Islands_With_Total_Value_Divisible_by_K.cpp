//#3619 Count Islands With Total Value Divisible by K - https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        stack<pair<int, int>> lands;
        int n = grid.size();
        int m = grid.front().size();
        int result = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                lands.push({i, j});
                int sum = grid[i][j] % k;
                grid[i][j] = 0;
                while(!lands.empty())
                {
                    int curX = lands.top().first;
                    int curY = lands.top().second;
                    lands.pop();
                    for(auto &dir : dirs)
                    {
                        int nextX = curX + dir[0];
                        int nextY = curY + dir[1];
                        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || !grid[nextX][nextY])
                            continue;
                        lands.push({nextX, nextY});
                        sum = (sum + grid[nextX][nextY]) % k;
                        grid[nextX][nextY] = 0;
                    }
                }
                if(!sum)
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{0, 2, 1, 0, 0}, {0, 5, 0, 0, 5}, {0, 0, 1, 0, 0}, {0, 1, 4, 7, 0}, {0, 2, 0, 0, 8}};
    int givenK = 5;
    int expectedAnswer = 2;
    assert(solution.countIslands(givenGrid, givenK) == expectedAnswer);

    givenGrid = {{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}};
    givenK = 3;
    expectedAnswer = 6;
    assert(solution.countIslands(givenGrid, givenK) == expectedAnswer);

    return 0;
}

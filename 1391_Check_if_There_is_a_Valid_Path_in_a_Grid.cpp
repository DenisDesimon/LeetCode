//#1391 Check if There is a Valid Path in a Grid - https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    int find(int cur, vector<int> &parents)
    {
        if(parents[cur] == -1)
            return cur;
        return parents[cur] = find(parents[cur], parents);
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> connections(n * m);
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int roads[7] = {0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011};
        auto isValid = [&](pair<int, int> cur)
        {
            return cur.first >= 0 && cur.first < n && cur.second >= 0 && cur.second < m;
        };
        vector<int> parents(n * m, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int road = roads[grid[i][j]];
                for(int k = 0; k < 4; k++)
                {
                    if(road & (1 << k))
                    {
                        pair<int, int> next = {i + dirs[k].first, j + dirs[k].second};
                        if(isValid(next) && (roads[grid[next.first][next.second]] & (1 << (k + 2) % 4)))
                        {
                            int leftParent = find(i * m + j, parents);
                            int rightParent = find(next.first * m + next.second, parents);
                            if(leftParent != rightParent)
                                parents[rightParent] = leftParent;
                        }
                    }
                }

            }
        }
        return find(0, parents) == find(n * m - 1, parents);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{2, 4, 3}, {6, 5, 2}};
    bool expectedAnswer = true;
    assert(solution.hasValidPath(givenGrid) == expectedAnswer);

    givenGrid = {{1, 2, 1}, {1, 2, 1}};
    expectedAnswer = false;
    assert(solution.hasValidPath(givenGrid) == expectedAnswer);

    return 0;
}

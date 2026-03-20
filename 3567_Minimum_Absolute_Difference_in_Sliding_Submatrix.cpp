//#3567 Minimum Absolute Difference in Sliding Submatrix - https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> result(n - k + 1, vector<int> (m - k + 1));
        for(int i = 0; i + k <= n; i++)
        {
            for(int j = 0; j + k <= m; j++)
            {
                vector<int> sorted;
                for(int x = i; x < i + k; x++)
                {
                    for(int y = j; y < j + k; y++)
                    {
                        sorted.push_back(grid[x][y]);
                    }
                }
                sort(sorted.begin(), sorted.end());
                int curMin = INT_MAX;
                for(int x = 1; x < k * k; x++)
                {
                    if(sorted[x] == sorted[x - 1])
                        continue;
                    curMin = min(curMin, sorted[x] - sorted[x - 1]);
                }
                if(curMin != INT_MAX)
                    result[i][j] = curMin;
            }
        }
        return result;
    }
};


int main()
{
    Solution solutin;
    vector<vector<int>> givenMatrix = {{1, 8}, {3, -2}};
    int givenK = 2;
    vector<vector<int>> expectedAnswer = {{2}};
    assert(solutin.minAbsDiff(givenMatrix, givenK) == expectedAnswer);

    givenMatrix = {{1, -2, 3}, {2, 3, 5}};
    givenK = 2;
    expectedAnswer = {{1, 2}};
    assert(solutin.minAbsDiff(givenMatrix, givenK) == expectedAnswer);

    return 0;
}

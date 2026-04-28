//#2033 Minimum Operations to Make a Uni-Value Grid - https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid.front().size();
        vector<int> sorted;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                sorted.push_back(grid[i][j]);
            }
        }
        sort(sorted.begin(), sorted.end());
        int mid = sorted[n * m / 2];
        int result = 0;
        for(int i = 0; i < n * m; i++)
        {
            if(abs(sorted[i] - mid) % x != 0)
                return -1;
            result += abs(sorted[i] - mid) / x;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{2, 4}, {6, 8}};
    int givenX = 2;
    int expectedAnswer = 4;
    assert(solution.minOperations(givenGrid, givenX) == expectedAnswer);

    givenGrid = {{1, 5}, {2, 3}};
    givenX = 1;
    expectedAnswer = 5;
    assert(solution.minOperations(givenGrid, givenX) == expectedAnswer);

    return 0;
}

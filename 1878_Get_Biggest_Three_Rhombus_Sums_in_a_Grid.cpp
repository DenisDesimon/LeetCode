//#1878 Get Biggest Three Rhombus Sums in a Grid - https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> result;
        int n = grid.size();
        int m = grid.front().size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                result.insert(grid[i][j]);
                if(result.size() > 3)
                    result.erase(result.begin());
                for(int len = 1; j - len >= 0 && j + len < m && i + 2 * len < n; len++)
                {
                    int x = i, y = j, sum = 0;
                    while(x < i + len)
                        sum += grid[x++][y++];
                    while(x < i + 2 * len)
                        sum += grid[x++][y--];
                    while(x > i + len)
                        sum += grid[x--][y--];
                    while(x > i)
                        sum += grid[x--][y++];
                    result.insert(sum);
                    if(result.size() > 3)
                        result.erase(result.begin());
                }
            }
        }
        return vector<int>(result.rbegin(), result.rend());
    }
};


int main()
{
    Solution solutin;
    vector<vector<int>> givenGrid = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<int> expectedAnswer = {228, 216, 211};
    assert(solutin.getBiggestThree(givenGrid) == expectedAnswer);

    givenGrid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    expectedAnswer = {20, 9, 8};
    assert(solutin.getBiggestThree(givenGrid) == expectedAnswer);

    return 0;
}

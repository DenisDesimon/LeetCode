//#3070 Count Submatrices with Top-Left Element and Sum Less Than k - https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i != 0)
                    grid[i][j] += grid[i - 1][j];
                if(j != 0)
                    grid[i][j] += grid[i][j - 1];
                if(i != 0 && j != 0)
                    grid[i][j] -= grid[i - 1][j - 1];
                if(grid[i][j] < k)
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solutin;
    vector<vector<int>> givenMatrix = {{7, 6, 3}, {6, 6, 1}};
    int givenK = 18;
    int expectedAnswer = 4;
    assert(solutin.countSubmatrices(givenMatrix, givenK) == expectedAnswer);

    givenMatrix = {{7, 2, 9}, {1 ,5, 0}, {2, 6, 6}};
    givenK = 20;
    expectedAnswer = 6;
    assert(solutin.countSubmatrices(givenMatrix, givenK) == expectedAnswer);

    return 0;
}

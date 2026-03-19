//#3212 Count Submatrices With Equal Frequency of X and Y - https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<int> sumX(m);
        vector<int> sumY(m);
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int curX = 0, curY = 0;
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'X')
                    curX++;
                else if(grid[i][j] == 'Y')
                    curY++;
                sumX[j] += curX;
                sumY[j] += curY;
                if(sumX[j] && sumX[j] == sumY[j])
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solutin;
    vector<vector<char>> givenMatrix = {{'X','Y','.'}, {'Y', '.', '.'}};
    int expectedAnswer = 3;
    assert(solutin.numberOfSubmatrices(givenMatrix) == expectedAnswer);

    givenMatrix = {{'X', 'X'}, {'X', 'Y'}};
    expectedAnswer = 0;
    assert(solutin.numberOfSubmatrices(givenMatrix) == expectedAnswer);

    return 0;
}

//#3643 Flip Square Submatrix Vertically - https://leetcode.com/problems/flip-square-submatrix-vertically/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j = y; j < y + k; j++)
        {
            for(int i = 0; i < k / 2; i++)
            {
                swap(grid[i + x][j], grid[x + k - 1 - i][j]);
            }
        }
        return grid;
    }
};

int main()
{
    Solution solutin;
    vector<vector<int>> givenMatrix = {{1, 2, 3, 4}, {5, 6, 7, 8} ,{9, 10, 11 ,12}, {13 ,14, 15, 16}};
    int givenK = 3;
    int givenX = 1;
    int givenY = 0;
    vector<vector<int>> expectedAnswer = {{1, 2, 3, 4}, {13, 14, 15, 8}, {9, 10 ,11, 12}, {5, 6, 7, 16}};
    assert(solutin.reverseSubmatrix(givenMatrix, givenX, givenY, givenK) == expectedAnswer);

    givenMatrix = {{3, 4, 2, 3}, {2, 3, 4, 2}};
    givenK = 2;
    givenX = 0;
    givenY = 2;
    expectedAnswer = {{3, 4, 4, 2}, {2, 3, 2, 3}};
    assert(solutin.reverseSubmatrix(givenMatrix, givenX, givenY, givenK) == expectedAnswer);

    return 0;
}

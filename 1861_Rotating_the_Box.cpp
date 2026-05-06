//#1861 Rotating the Box - https://leetcode.com/problems/rotating-the-box/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid.front().size();
        vector<vector<char>> result(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++)
        {
            int empty = m - 1;
            for(int j = m - 1; j >= 0; j--)
            {
                if(boxGrid[i][j] == '#')
                {
                    result[empty][n - 1 - i] = '#';
                    empty--;
                }else if(boxGrid[i][j] == '*')
                {
                    result[j][n - 1 - i] = '*';
                    empty = j - 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> givenBoxGrid = {{'#', '.', '#'}};
    vector<vector<char>> expectedAnswer = {{'.'}, {'#'}, {'#'}};
    assert(solution.rotateTheBox(givenBoxGrid) == expectedAnswer);

    givenBoxGrid = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
    expectedAnswer = {{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}};
    assert(solution.rotateTheBox(givenBoxGrid) == expectedAnswer);

    return 0;
}

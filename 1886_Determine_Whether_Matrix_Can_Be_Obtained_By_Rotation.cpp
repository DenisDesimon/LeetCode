//#1886 Determine Whether Matrix Can Be Obtained By Rotation - https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> getRotated(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat.front().size();
        vector<vector<int>> result(m, vector<int>(n));
        for(int j = m - 1; j >= 0; j--)
        {
            for(int i = 0; i < n; i++)
            {
                result[m - 1 - j][i] = mat[i][j];
            }
        }
        return result;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)
            return true;
        auto rotated = mat;
        for(int i = 0; i < 3; i++)
        {
            rotated = getRotated(rotated);
            if(rotated == target)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> givenTarget = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    bool expectedAnswer = true;
    assert(solution.findRotation(givenMatrix, givenTarget) == expectedAnswer);

    givenMatrix = {{0, 1}, {1, 1}};
    givenTarget = {{1, 0}, {0, 1}};
    expectedAnswer = false;
    assert(solution.findRotation(givenMatrix, givenTarget) == expectedAnswer);

    return 0;
}

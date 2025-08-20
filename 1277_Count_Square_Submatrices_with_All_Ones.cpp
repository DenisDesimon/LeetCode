//#1277 Count Square Submatrices with All Ones - https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix.front().size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        int result = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j])
                {
                    dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    result += dp[i + 1][j + 1];
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    long long expectedAnswer = 15;
    assert(solution.countSquares(givenMatrix) == expectedAnswer);

    givenMatrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    expectedAnswer = 7;
    assert(solution.countSquares(givenMatrix) == expectedAnswer);

    return 0;
}

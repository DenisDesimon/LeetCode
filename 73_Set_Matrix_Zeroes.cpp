//#73 Set Matrix Zeroes - https://leetcode.com/problems/set-matrix-zeroes/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool null_col = false;
        for(int i = 0; i < (int)matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
                null_col = true;
            for(int j = 1; j < (int)matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < (int)matrix.size(); i++)
        {
            for(int j = 1; j < (int)matrix[0].size(); j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] == 0)
        {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if(null_col)
        {
            for(int i = 0; i < (int)matrix.size(); i++)
                matrix[i][0] = 0;
        }

    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{1, 1, 1}, {0, 1, 2}};
    vector<vector<int>> expected_answer = {{0, 1, 1}, {0, 0, 0}};
    solution.setZeroes(given_matrix);
    assert(given_matrix == expected_answer);

    given_matrix = {{0, 1, 2, 0},
                    {3, 4, 5, 2},
                    {1, 3, 1, 5}};
    expected_answer = {{0, 0, 0, 0},
                      {0, 4, 5, 0},
                      {0, 3, 1, 0}};
    solution.setZeroes(given_matrix);
    assert(given_matrix == expected_answer);

    return 0;
}

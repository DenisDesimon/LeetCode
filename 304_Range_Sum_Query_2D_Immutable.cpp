//#304 Range Sum Query 2D - Immutable - https://leetcode.com/problems/range-sum-query-2d-immutable/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class NumMatrix {
    vector<vector<int>> Square_Sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.empty())
            Square_Sum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for(int i = 1; i < (int)matrix.size() + 1; i++)
        {
            for(int j = 1; j < (int)matrix[0].size() + 1; j++)
            {
                Square_Sum[i][j] = Square_Sum[i - 1][j] + Square_Sum[i][j - 1] + matrix[i - 1][j - 1]
                                   - Square_Sum[i -1][j -1];
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return Square_Sum[row2 + 1][col2 + 1] - Square_Sum[row2 + 1][col1] - Square_Sum[row1][col2 + 1]
               + Square_Sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> given_matrix = {{3, 0, 1, 4, 2},
                                        {5, 6, 3, 2, 1},
                                        {1, 2, 0, 1, 5},
                                        {4, 1, 0, 1, 7},
                                        {1, 0, 3, 0, 5}};
    NumMatrix solution(given_matrix);
    int expected_answer = 8;
    assert(solution.sumRegion(2, 1, 4, 3) == expected_answer);

    expected_answer = 11;
    assert(solution.sumRegion(1, 1, 2, 2) == expected_answer);

    expected_answer = 12;
    assert(solution.sumRegion(1, 2, 2, 4) == expected_answer);

    return 0;
}

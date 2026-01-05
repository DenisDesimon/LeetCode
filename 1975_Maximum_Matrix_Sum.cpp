//#1975 Maximum Matrix Sum - https://leetcode.com/problems/maximum-matrix-sum/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int countNegative = 0, minNum = INT_MAX;
        for(auto &row : matrix)
        {
            for(auto &col : row)
            {
                if(col < 0)
                    countNegative++;
                minNum = min(abs(col), minNum);
                result += abs(col);
            }
        }
        return countNegative % 2 ? result - 2 * minNum : result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{1, -1}, {-1, 1}};
    int expectedAnswer = 4;
    assert(solution.maxMatrixSum(givenMatrix) == expectedAnswer);

    givenMatrix = {{1 ,2, 3}, {-1, -2, -3}, {1, 2, 3}};
    expectedAnswer = 16;
    assert(solution.maxMatrixSum(givenMatrix) == expectedAnswer);

    return 0;
}

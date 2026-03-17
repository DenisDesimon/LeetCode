//#1727 Largest Submatrix With Rearrangements - https://leetcode.com/problems/largest-submatrix-with-rearrangements/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i != 0 && matrix[i][j])
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            vector<int> sorted = matrix[i];
            sort(sorted.begin(), sorted.end(), greater<int>());
            for(int k = 0; k < m; k++)
                result = max(result, sorted[k] * (k + 1));
        }
        return result;
    }
};

int main()
{
    Solution solutin;
    vector<vector<int>> givenMatrix = {{1, 0, 1, 0, 1}};
    int expectedAnswer = 3;
    assert(solutin.largestSubmatrix(givenMatrix) == expectedAnswer);

    givenMatrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    expectedAnswer = 4;
    assert(solutin.largestSubmatrix(givenMatrix) == expectedAnswer);

    return 0;
}

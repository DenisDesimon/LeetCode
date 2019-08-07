//#74 Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row = 0;
        for(int i = matrix.size() / 2; i > 0; i /= 2)
        {
            while(row + i < (int)matrix.size() && target >= matrix[row + i][0])
                row += i;
        }
        auto lower = lower_bound(matrix[row].begin(), matrix[row].end(), target);
        if(lower == matrix[row].end())
            return false;
        return *lower == target;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{1,   3,  5,  7},
                                        {10, 11, 16, 20},
                                        {23, 30, 34, 50}};
    int given_target = 11;
    bool expected_answer = true;
    assert(solution.searchMatrix(given_matrix, given_target) == expected_answer);

    given_target = 52;
    expected_answer = false;
    assert(solution.searchMatrix(given_matrix, given_target) == expected_answer);

    return 0;
}

//#54 Spiral Matrix - https://leetcode.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int left = 0, top = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        while(left <= right && top <= bottom)
        {
            for(int cur_left = left; cur_left <= right; cur_left++)
                result.push_back(matrix[top][cur_left]);
            for(int cur_top = top + 1; cur_top <= bottom; cur_top++)
                result.push_back(matrix[cur_top][right]);
            if(left < right && top < bottom)
            {
            for(int cur_right = right - 1; cur_right > left; cur_right--)
                result.push_back(matrix[bottom][cur_right]);
            for(int cur_bottom = bottom; cur_bottom > top; cur_bottom--)
                result.push_back(matrix[cur_bottom][left]);
            }
            left++, right--, top++, bottom--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{3}, {2}};
    vector<int> expected_answer = {3, 2};
    assert(solution.spiralOrder(given_matrix) == expected_answer);

    given_matrix = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

    expected_answer = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    assert(solution.spiralOrder(given_matrix) == expected_answer);

    return 0;
}

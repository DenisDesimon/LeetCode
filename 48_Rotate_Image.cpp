//#48 Rotate Image - https://leetcode.com/problems/rotate-image/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int row = 0; row < (int)matrix.size(); row++)
        {
            for(int col = row + 1; col < (int)matrix[0].size(); col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{1, 2, 3},
                                        {4, 5, 6},
                                        {7, 8, 9}};

    vector<vector<int>> expected_answer = {{7, 4, 1},
                                           {8, 5, 2},
                                           {9, 6, 3}};

    solution.rotate(given_matrix);
    assert(given_matrix == expected_answer);

    return 0;

}

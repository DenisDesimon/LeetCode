//#1582 Special Positions in a Binary Matrix - https://leetcode.com/problems/special-positions-in-a-binary-matrix/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.front().size();
        vector<int> rows(n), cols(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] && rows[i] == 1 && cols[j] == 1)
                {
                    result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    int expectedAnswer = 1;
    assert(solution.numSpecial(givenMat) == expectedAnswer);

    givenMat = {{1, 0,0 }, {0, 1, 0}, {0, 0, 1}};
    expectedAnswer = 3;
   assert(solution.numSpecial(givenMat) == expectedAnswer);

    return 0;
}

//#498 Diagonal Traverse - https://leetcode.com/problems/diagonal-traverse/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int rows = mat.size(), cols = mat.front().size();
        for(int startD = 0; startD < rows + cols - 1; startD++)
        {
            vector<int> cur;
            int row = startD < cols ? 0 : startD - cols + 1;
            int col = startD < cols ? startD : cols - 1;
            while(row < rows && col >= 0)
                cur.push_back(mat[row++][col--]);
            if(startD % 2 == 0)
                reverse(cur.begin(), cur.end());
            result.insert(result.end(), cur.begin(), cur.end());
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> expectedAnswer = {1, 2, 4, 7, 5, 3, 6, 8, 9};
    assert(solution.findDiagonalOrder(given_mat) == expectedAnswer);

    given_mat = {{1, 2}, {3, 4}};
    expectedAnswer = {1, 2, 3, 4};
    assert(solution.findDiagonalOrder(given_mat) == expectedAnswer);

    return 0;
}


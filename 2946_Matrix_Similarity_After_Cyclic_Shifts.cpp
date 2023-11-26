//#2946 Matrix Similarity After Cyclic Shifts - https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        k %= n;
        for(int i = 0; i < (int)mat.size(); i++)
        {
            for(int j = 0; j < (n + 1) / 2; j++)
            {
                    if(mat[i][(j + k) % n] != mat[i][j])
                        return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> given_mat = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
    int given_k = 2;
    bool expected_answer = true;
    assert(solution.areSimilar(given_mat, given_k) == expected_answer);

    given_mat = {{9, 1, 8, 9, 2, 9, 1, 8, 9, 2}, {10, 2, 7, 8, 9, 10, 2, 7, 8, 9}, {7, 6, 6, 9, 5, 7, 6, 6, 9, 5}};
    given_k = 5;
    expected_answer = true;
    assert(solution.areSimilar(given_mat, given_k) == expected_answer);

    return 0;
}

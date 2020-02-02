//#1341 The K Weakest Rows in a Matrix - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        vector<pair<int, int>> hash;
        for(int i = 0; i < (int)mat.size(); i++)
        {
            int j = mat[i].size() - 1;
            for(; j >= 0; j--)
            {
                if(mat[i][j] == 1)
                    break;
            }
            hash.push_back({i, j + 1});
        }
        sort(hash.begin(), hash.end(), [](pair<int, int> a, pair<int, int> b){if(a.second == b.second) return a.first < b.first; return a.second < b.second;});
        for(int i = 0; i < k; i++)
            result.push_back(hash[i].first);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_mat = {{1, 1, 0, 0, 0},
                                    {1, 1, 1, 1, 0},
                                    {1, 0, 0, 0, 0},
                                    {1, 1, 0, 0, 0},
                                    {1, 1, 1, 1, 1}};
    int given_k = 3;
    vector<int> expected_answer = {2, 0, 3};
    assert(solution.kWeakestRows(given_mat, given_k) == expected_answer);

    given_mat = {{1, 0, 0, 0},
                 {1, 1, 1, 1},
                 {1, 0, 0, 0},
                 {1, 0, 0, 0}};
    given_k = 2;
    expected_answer = {0, 2};
    assert(solution.kWeakestRows(given_mat, given_k) == expected_answer);

    return 0;
}

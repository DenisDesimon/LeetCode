//#1424 Diagonal Traverse II - https://leetcode.com/problems/diagonal-traverse-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> hash;
        vector<int> result;
        int diag_num = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            for(int j = 0; j < (int)nums[i].size(); j++)
            {
                hash[i + j].insert(hash[i + j].begin(), nums[i][j]);
                diag_num = max(diag_num, i + j);
            }
        }
        for(int i = 0; i <= diag_num; i++)
            result.insert(result.end(), hash[i].begin(), hash[i].end());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nums = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    vector<int> expected_answer = {1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
    assert(solution.findDiagonalOrder(given_nums) == expected_answer);

    given_nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    expected_answer = {1, 4, 2, 7, 5, 3, 8, 6, 9};
    assert(solution.findDiagonalOrder(given_nums) == expected_answer);

    return 0;
}

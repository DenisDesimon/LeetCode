//#1380 Lucky Numbers in a Matrix - https://leetcode.com/problems/lucky-numbers-in-a-matrix/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> row;
        vector<int> result;
        for(int i = 0; i < (int)matrix.size(); i++)
            row.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        for(int i = 0; i < (int)matrix[0].size(); i++)
        {
            int max_num = matrix[0][i];
            for(int j = 1; j < (int)matrix.size(); j++)
            {
                max_num = max(max_num, matrix[j][i]);
            }
            if(row.count(max_num))
                result.push_back(max_num);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> expected_answer = {15};
    assert(solution.luckyNumbers(given_matrix) == expected_answer);

    given_matrix = {{7, 8}, {1, 2}};
    expected_answer = {7};
    assert(solution.luckyNumbers(given_matrix) == expected_answer);

    return 0;
}

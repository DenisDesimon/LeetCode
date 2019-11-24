//#1252 Cells with Odd Values in a Matrix - https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int result = 0;
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for(auto& index : indices)
        {
            rows[index[0]]++;
            cols[index[1]]++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((rows[i] + cols[j]) & 1)
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 2, given_m = 3;
    vector<vector<int>> given_indices = {{0, 1}, {1, 1}};
    int expected_answer = 6;
    assert(solution.oddCells(given_n, given_m, given_indices) == expected_answer);

    given_n = 2, given_m = 2;
    given_indices = {{1, 1}, {0, 0}};
    expected_answer = 0;
    assert(solution.oddCells(given_n, given_m, given_indices) == expected_answer);

    return 0;
}

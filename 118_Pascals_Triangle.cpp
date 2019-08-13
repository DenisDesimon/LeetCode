//#118 Pascal's Triangle - https://leetcode.com/problems/pascals-triangle/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if(numRows == 0)
            return result;
        result[0].push_back(1);
        for(int i = 1; i < numRows; i++)
        {
            result[i].push_back(1);
            for(int j = 1; j < (int)result[i - 1].size(); j++)
            {
                result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_numRows = 5;
    vector<vector<int>> expected_answer = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1,4,6,4,1}};
    assert(solution.generate(given_numRows) == expected_answer);

    given_numRows = 4;
    expected_answer.pop_back();
    assert(solution.generate(given_numRows) == expected_answer);

    return 0;
}

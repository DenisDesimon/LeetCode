//#119 Pascal's Triangle II - https://leetcode.com/problems/pascals-triangle-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        rowIndex++;
        result = {1};
        for(int i = 1; i < rowIndex; i++)
        {
            for(int j = 1; j < (int)result.size(); j++)
            {
                result[j - 1] = result[j - 1] + result[j];
            }
            result.insert(result.begin(), 1);
            result.back() = 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_numRows = 3;
    vector<int> expected_answer = {1, 3, 3, 1};
    assert(solution.getRow(given_numRows) == expected_answer);

    given_numRows = 4;
    expected_answer = {1, 4, 6, 4, 1};
    assert(solution.getRow(given_numRows) == expected_answer);

    return 0;
}

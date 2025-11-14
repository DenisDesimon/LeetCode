//#2536 Increment Submatrices by One - https://leetcode.com/problems/increment-submatrices-by-one/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n, vector<int>(n));
        vector<vector<int>> prefix(n + 1, vector<int>(n + 1));
        for(auto &query : queries)
        {
            for(int row = query[0]; row <= query[2]; row++)
            {
                prefix[row][query[1]] += 1;
                prefix[row][query[3] + 1] -= 1;
            }
        }
        for(int i = 0; i < n; i++)
        {
           int sum = 0;
            for(int j = 0; j < n; j++)
            {
                sum += prefix[i][j];
                result[i][j] = sum;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenQueries = {{1, 1 ,2, 2}, {0, 0, 1, 1}};
    int givenN = 3;
    vector<vector<int>> expectedAnswer = {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};
    assert(solution.rangeAddQueries(givenN, givenQueries) == expectedAnswer);

    givenQueries = {{0, 0, 1, 1}};
    givenN = 2;
    expectedAnswer = {{1, 1}, {1, 1}};
    assert(solution.rangeAddQueries(givenN, givenQueries) == expectedAnswer);

    return 0;
}

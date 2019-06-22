//#62 Unique Paths - https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int result[m][n];
        for(int col = 0; col < m; col++)
        {
            result[col][0] = 1;
        }

        for(int row = 0; row < n; row++)
        {
            result[0][row] = 1;
        }

        for(int col = 1; col < m; col++)
        {
            for(int row = 1; row < n; row++)
            {
                result[col][row] = result[col - 1][row] + result[col][row - 1];
            }
        }
        return result[m - 1][n - 1];
    }
};



int main()
{
    Solution solution;
    int given_m = 7, given_n = 3;
    int  expected_answer = 28;
    assert(solution.uniquePaths(given_m, given_n) == expected_answer);

    given_m = 3, given_n = 2;
    expected_answer = 3;
    assert(solution.uniquePaths(given_m, given_n) == expected_answer);

    return 0;
}

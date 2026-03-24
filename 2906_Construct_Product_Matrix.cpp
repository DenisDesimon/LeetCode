//#2906 Construct Product Matrix - https://leetcode.com/problems/construct-product-matrix/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        long long suffix = 1, prefix = 1;
        int mod = 12345;
        vector<vector<int>> result(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                result[i][j] = (result[i][j] * prefix) % mod;
                result[n - 1 - i][m - 1 - j] = (result[n - 1 - i][m - 1 - j] * suffix) % mod;
                prefix = (prefix * grid[i][j]) % mod;
                suffix = (suffix * grid[n - 1 - i][m - 1 - j]) % mod;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{1, 2}, {3, 4}};
    vector<vector<int>> expectedAnswer = {{24, 12}, {8, 6}};
    assert(solution.constructProductMatrix(givenMatrix) == expectedAnswer);

    givenMatrix = {{12345}, {2}, {1}};
    expectedAnswer = {{2}, {0}, {0}};
    assert(solution.constructProductMatrix(givenMatrix) == expectedAnswer);

    return 0;
}

//#1895 Largest Magic Square - https://leetcode.com/problems/largest-magic-square/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> prefixVert(n + 1, vector<int>(m + 1));
        vector<vector<int>> prefixHor(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                prefixVert[i][j] += prefixVert[i - 1][j] + grid[i - 1][j - 1];
                prefixHor[i][j] += prefixHor[i][j - 1] + grid[i - 1][j - 1];
            }
        }
        int result = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int len = min(n - i, m - j); len > result; len--)
                {
                    int sum = prefixVert[i + len][j] - prefixVert[i - 1][j];
                    int cur = 0, d1 = 0, d2 = 0;
                    for(; cur <= len; cur++)
                    {
                        if(sum != prefixVert[i + len][j + cur] - prefixVert[i - 1][j + cur] || sum != prefixHor[i + cur][j + len] - prefixHor[i + cur][j - 1])
                            break;
                        d1 += grid[i - 1 + cur][j - 1 + cur];
                        d2 += grid[i - 1 + len - cur][j - 1 + cur];
                    }
                    if(cur > len && d1 == sum && d2 == sum)
                        result = len;
                }
            }
        }
        return result + 1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid  = {{7, 1, 4, 5, 6} ,{2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
    long long expectedAnswer = 3;
    assert(solution.largestMagicSquare(givenGrid) == expectedAnswer);

    givenGrid = {{5, 1, 3, 1},{ 9, 3, 3, 1}, {1, 3, 3, 8}};
    expectedAnswer = 2;
    assert(solution.largestMagicSquare(givenGrid) == expectedAnswer);

    return 0;
}

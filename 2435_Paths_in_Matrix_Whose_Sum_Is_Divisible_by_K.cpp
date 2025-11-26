//#2435 Paths in Matrix Whose Sum Is Divisible by K - https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid.front().size();
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> countRemainders(n, vector<vector<int>>(m, vector<int>(k)));
        countRemainders.front().front()[grid.front().front() % k] = 1;
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int t = 0; t < k; t++)
                {
                    if(countRemainders[i][j][t])
                    {
                        if(i != n - 1)
                        {
                            countRemainders[i + 1][j][(t + grid[i + 1][j]) % k] += countRemainders[i][j][t];
                            countRemainders[i + 1][j][(t + grid[i + 1][j]) % k] %= mod;
                        }
                        if(j != m - 1)
                        {
                            countRemainders[i][j + 1][(t + grid[i][j + 1]) % k] += countRemainders[i][j][t];
                            countRemainders[i][j + 1][(t + grid[i][j + 1]) % k] %= mod;
                        }
                    }
                }
            }
        }
        return countRemainders.back().back().front();
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int givenK = 3;
    int expectedAnswer = 2;
    assert(solution.numberOfPaths(givenGrid, givenK) == expectedAnswer);

    givenGrid = {{7, 3, 4, 9}, {2, 3, 6, 2}, {2 ,3, 7, 0}};
    givenK = 1;
    expectedAnswer = 10;
    assert(solution.numberOfPaths(givenGrid, givenK) == expectedAnswer);

    return 0;
}

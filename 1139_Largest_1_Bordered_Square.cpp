//#1139 Largest 1-Bordered Square - https://leetcode.com/problems/largest-1-bordered-square/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size(), result = 0;
       vector<vector<int>> hor(n, vector<int>(m, 0)), ver(n, vector<int>(m, 0));
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(grid[i][j] == 1)
               {
                   hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
                   ver[i][j] = i == 0 ? 1 : ver[i - 1][j] + 1;
               }
           }
       }
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
                int square = min(hor[i][j], ver[i][j]);
                while(square > result)
                {
                    if(ver[i][j - square + 1] >= square && hor[i - square + 1][j] >= square)
                        result = square;
                    square--;
                }
           }
       }
       return result * result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int expected_answer = 9;
    assert(solution.largest1BorderedSquare(given_grid) == expected_answer);

    given_grid = {{1, 1, 0, 0}};
    expected_answer = 1;
    assert(solution.largest1BorderedSquare(given_grid) == expected_answer);

    return 0;
}

//#221 Maximal Square - https://leetcode.com/problems/maximal-square/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int result = 0;
        vector<vector<int>> vert(n, vector<int>(m, 0)), hor;
        hor = vert;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    vert[i][j] = i == 0 ? 1 : vert[i - 1][j] + 1;
                    hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int square = min(vert[i][j], hor[i][j]);
                while(square > result)
                {
                    bool is_square = true;
                    for(int len = 1; len < square; len++)
                    {
                        if(vert[i][j - len] < square)
                        {
                            is_square = false;
                            break;
                        }
                    }
                    if(!is_square)
                    {
                        square--;
                        continue;
                    }
                    for(int len = 1; len < square; len++)
                    {
                        if(hor[i - len][j] < square)
                        {
                            is_square = false;
                            break;
                        }
                    }
                    if(is_square)
                    {
                        result = square;
                        break;
                    }
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
    vector<vector<char>> given_nums = {{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
    int expected_answer = 4;
    assert(solution.maximalSquare(given_nums) == expected_answer);

    return 0;
}

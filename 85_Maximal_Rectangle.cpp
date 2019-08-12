//#85 Maximal Rectangle - https://leetcode.com/problems/maximal-rectangle/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int result = 0;
        vector<vector<int>> hor(n, vector<int>(m, 0)), vert(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(matrix[i][j] == '1')
                {
                    hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
                    vert[i][j] = i == 0 ? 1 : vert[i - 1][j] + 1;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                int hight = vert[i][j], width = hor[i][j];
                if(hight * width > result)
                {
                    for(int high = 1; high <= hight; high++)
                    {
                        width = min(width, hor[i - high +  1][j]);
                        result = max(result, width * high);
                    }

                }
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_matrix = {
                    {'1', '0', '1', '0', '0'},
                    {'1', '0', '1', '1', '1'},
                    {'1', '1', '1', '1', '1'},
                    {'1', '0', '0', '1', '0'}};
    int expected_answer = 6;
    assert(solution.maximalRectangle(given_matrix) == expected_answer);

    expected_answer = 9;
    given_matrix = {{'0','1','1','0','1'},
                    {'1','1','0','1','0'},
                    {'0','1','1','1','0'},
                    {'1','1','1','1','0'},
                    {'1','1','1','1','1'},
                    {'0','0','0','0','0'}};
    assert(solution.maximalRectangle(given_matrix) == expected_answer);

    return 0;
}

//#3933 Largest Local Values in a Matrix II - https://leetcode.com/problems/largest-local-values-in-a-matrix-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    bool check(int i, int j, vector<vector<int>>& matrix, vector<vector<vector<int>>> &prefix){
        int val = matrix[i][j];
        int n = prefix[0].size() - 1;
        int m = prefix[0][0].size() - 1;
        int top = max(0, i - val);
        int bot = min(n - 1, i + val);
        int left = max(0, j - val);
        int right = min(m - 1, j + val);

        int count = prefix[val][bot + 1][right + 1] - prefix[val][top][right + 1] + prefix[val][top][left] - prefix[val][bot + 1][left];

        int directionX[4] = {-val, -val, val, val};
        int directionY[4] = {-val, val, -val, val};

        for(int k = 0; k < 4; k++)
        {
            int cornerX = i + directionX[k];
            int cornerY = j + directionY[k];
            if(cornerX >= 0 && cornerX < n && cornerY >= 0 && cornerY < m && matrix[cornerX][cornerY] > val)
                count--;
        }

        return count == 0;
    }
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        int result = 0;
        vector<vector<vector<int>>> prefix(201, vector<vector<int>>(n + 1, vector<int>(m + 1)));
        for(int val = 0; val < 201; val++)
        {
            for(int i = 0; i < n; i++)
            {
                int cur = 0;
                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] > val)
                        cur++;
                    prefix[val][i + 1][j + 1] = cur + prefix[val][i][j + 1];
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                    continue;
                if(check(i, j, matrix, prefix))
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix  = {{1, 2}, {3, 4}};
    int expectedAnswer = 1;
    assert(solution.countLocalMaximums(givenMatrix) == expectedAnswer);

    givenMatrix  = {{1, 0, 1}, {0, 1, 0}, {1 ,0, 1}};
    expectedAnswer = 5;
    assert(solution.countLocalMaximums(givenMatrix) == expectedAnswer);

    return 0;
}

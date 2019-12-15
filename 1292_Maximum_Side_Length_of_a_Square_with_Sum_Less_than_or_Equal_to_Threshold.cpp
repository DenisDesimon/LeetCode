//#1292 Maximum Side Length of a Square with Sum Less than or Equal to Threshold - https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int result = 0;
        vector<vector<int>> Prefix(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                Prefix[i][j] = Prefix[i - 1][j] + Prefix[i][j - 1] - Prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int size = min(i, j);
                for(int t = result + 1; t <= size; t++)
                {
                    int sum = Prefix[i][j] - Prefix[i - t][j] - Prefix[i][j - t] + Prefix[i - t][j - t];
                    if(sum <= threshold)
                        result = t;
                    else
                        break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_mat = {{18,70}, {61,1}, {25,85}, {14,40}, {11,96}, {97,96}, {63,45}};
    int given_threshold = 40184;
    int expected_answer = 2;
    assert(solution.maxSideLength(given_mat, given_threshold) == expected_answer);

    given_mat = {{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
    given_threshold = 4;
    expected_answer = 2;
    assert(solution.maxSideLength(given_mat, given_threshold) == expected_answer);

    return 0;
}

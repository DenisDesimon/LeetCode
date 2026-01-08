//#1458 Max Dot Product of Two Subsequences - https://leetcode.com/problems/max-dot-product-of-two-subsequences/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = nums1[i] * nums2[j];
                if(i && j)
                    dp[i][j] += max(dp[i - 1][j - 1], 0);
                if(i)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);

            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums1 = {2, 1, -2, 5};
    vector<int> givenNums2 = {3, 0, -6};
    int expectedAnswer = 18;
    assert(solution.maxDotProduct(givenNums1, givenNums2) == expectedAnswer);

    givenNums1 = {3, -2};
    givenNums2 = {2, -6, 7};
    expectedAnswer = 21;
    assert(solution.maxDotProduct(givenNums1, givenNums2) == expectedAnswer);

    return 0;
}

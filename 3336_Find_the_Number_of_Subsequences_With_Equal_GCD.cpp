//#3336 Find the Number of Subsequences With Equal GCD - https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        int result = 0;
        for(int &num : nums)
        {
            vector<vector<int>> ndp(m + 1, vector<int>(m + 1));
            for(int j = 0; j <= m; j++)
            {
                int divisor1 = gcd(j, num);
                for(int k = 0; k <= m; k++)
                {
                    int val = dp[j][k];
                    if(val == 0)
                        continue;
                    int divisor2 = gcd(k, num);
                    ndp[j][k] = (ndp[j][k] + val) % MOD;
                    ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                    ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
                }
            }
            dp.swap(ndp);
        }
        for(int j = 1; j <= m; j++)
            result = (result + dp[j][j]) % MOD;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4};
    int expectedAnswer = 10;
    assert(solution.subsequencePairCount(givenNums) == expectedAnswer);

    givenNums = {10, 20, 30};
    expectedAnswer = 2;
    assert(solution.subsequencePairCount(givenNums) == expectedAnswer);

    return 0;
}

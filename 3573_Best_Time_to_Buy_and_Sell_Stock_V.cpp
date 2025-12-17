//#3573 Best Time to Buy and Sell Stock V - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(3));
        for(int i = 1; i <= k; i++)
        {
            dp[i][1] = -prices[0];
            dp[i][2] = prices[0];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = k; j  > 0; j--)
            {
                long long buy = dp[j][2] - prices[i];
                long long sell = dp[j][1] + prices[i];
                dp[j][0] = max(dp[j][0], max(sell, buy));
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
                dp[j][2] = max(dp[j][2], dp[j - 1][0] + prices[i]);
            }
        }
        return dp[k][0];
    }
};


int main()
{
    Solution solution;
    vector<int> givenPrices = {1, 7, 9, 8, 2};
    int givenK = 2;
    int expected_answer = 14;
    assert(solution.maximumProfit(givenPrices, givenK) == expected_answer);

    givenPrices = {12, 16, 19, 19, 8, 1, 19, 13, 9};
    givenK = 3;
    expected_answer = 36;
    assert(solution.maximumProfit(givenPrices, givenK) == expected_answer);

    return 0;
}

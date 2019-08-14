//#123 Best Time to Buy and Sell Stock III - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int max_sum = -prices[0];
        for(int i = 1; i < n; i++)
        {
            max_sum = max(max_sum, -prices[i]);
            dp[0][i] = max(dp[0][i - 1], prices[i] + max_sum);
        }
        max_sum = -prices[0];
        for(int i = 1; i < n; i++)
        {
            max_sum = max(max_sum, dp[0][i - 1] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], prices[i] + max_sum);
        }
        return dp[1][n - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {2, 1, 4, 5, 2, 9, 7};
    int expected_answer = 11;
    assert(solution.maxProfit(given_prices) == expected_answer);

    given_prices = {3, 3, 5, 0, 0, 3, 1, 4};
    expected_answer = 6;
    assert(solution.maxProfit(given_prices) == expected_answer);

    return 0;
}

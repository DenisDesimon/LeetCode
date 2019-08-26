//#188 Best Time to Buy and Sell Stock IV - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k == 0)
            return 0;
        if(k > (int)prices.size())
        {
            int result = 0;
            for(int i = 1; i < (int)prices.size(); i++)
            {
                if(prices[i] > prices[i - 1])
                    result += prices[i] - prices[i - 1];
            }
            return result;
        }
        else{
            vector<vector<int>> dp(k, vector<int>(prices.size(), 0));
            int max_sum = -prices[0];
            for(int i = 1; i < (int)prices.size(); i++)
            {
                max_sum = max(max_sum, -prices[i]);
                dp[0][i] = max(dp[0][i - 1], max_sum + prices[i]);
            }
            for(int i = 1; i < k; i++)
            {
                max_sum = -prices[0];
                for(int j = 1; j < (int)prices.size(); j++)
                {
                    max_sum = max(max_sum, dp[i - 1][j] - prices[j]);
                    dp[i][j] = max(dp[i][j - 1], max_sum + prices[j]);
                }
            }
            return dp.back().back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {2, 4, 1};
    int given_k = 2;
    int expected_answer = 2;
    assert(solution.maxProfit(given_k, given_prices) == expected_answer);

    given_prices = {3, 2, 6, 5, 0, 3};
    given_k = 20000000;
    expected_answer = 7;
    assert(solution.maxProfit(given_k, given_prices) == expected_answer);

    return 0;
}

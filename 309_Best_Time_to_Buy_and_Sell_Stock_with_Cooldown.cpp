//#309 Best Time to Buy and Sell Stock with Cooldown - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        vector<int> dp(prices.size() + 1, 0);
        int max_sum = -prices[0];
        for(int i = 2; i <= (int)prices.size(); i++)
        {
            dp[i] = max(dp[i - 1], prices[i - 1] + max_sum);
            max_sum = max(max_sum, dp[i - 2] - prices[i - 1]);
        }
        return dp[prices.size()];
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {1, 2, 3, 0, 2};
    int expected_answer = 3;
    assert(solution.maxProfit(given_prices) == expected_answer);

    given_prices = {1, 2, 4};
    expected_answer = 3;
    assert(solution.maxProfit(given_prices) == expected_answer);

    return 0;
}

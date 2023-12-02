//#2944 Minimum Number of Coins for Fruits - https://leetcode.com/problems/minimum-number-of-coins-for-fruits/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<int> dp(prices.size() + 1, 0);
        dp[1] = prices[0];
        for(int i = 2; i <= (int)prices.size(); i++)
        {
            dp[i] = dp[i - 1] + prices[i - 1];
            for(int j = i - 1; j * 2 >= i; j--)
            {
                dp[i] = min(dp[i], dp[j - 1] + prices[j - 1]);
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {1,10,1,1};
    int expected_answer = 2;
    assert(solution.minimumCoins(given_prices) == expected_answer);

    given_prices = {1, 10, 1, 1, 3, 1, 2};
    expected_answer = 3;
    assert(solution.minimumCoins(given_prices) == expected_answer);

    return 0;
}

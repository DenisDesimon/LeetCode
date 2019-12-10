//#518 Coin Change 2 - https://leetcode.com/problems/coin-change-2/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(auto& coin : coins)
        {
            for(int cur_amount = coin; cur_amount <= amount; cur_amount++)
            {
                dp[cur_amount] += dp[cur_amount - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution solution;
    vector<int> given_coins = {1, 2, 5};
    int given_amount = 5;
    int expected_answer = 4;
    assert(solution.change(given_amount, given_coins) == expected_answer);

    given_coins = {10};
    given_amount = 10;
    expected_answer = 1;
    assert(solution.change(given_amount, given_coins) == expected_answer);

    return 0;
}

//#121 Best Time to Buy and Sell Stock - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int result = 0, min_price = prices[0];
        for(int i = 1; i < (int)prices.size(); i++)
        {
            result = max(result, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {7, 1, 5, 3, 6, 4};
    int expected_answer = 5;
    assert(solution.maxProfit(given_prices) == expected_answer);

    given_prices = {7, 6, 4, 3, 1};
    expected_answer = 0;
    assert(solution.maxProfit(given_prices) == expected_answer);

    return 0;
}

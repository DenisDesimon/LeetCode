//#714 Best Time to Buy and Sell Stock with Transaction Fee - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty())
            return 0;
       int hold = -prices[0], sum = 0;
       for(int i = 1; i < (int)prices.size(); i++)
       {
           sum = max(sum, hold + prices[i] - fee);
           hold = max(hold, sum - prices[i]);
       }
       return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {1, 3, 2, 8, 4, 9};
    int given_fee = 2;
    int expected_answer = 8;
    assert(solution.maxProfit(given_prices, given_fee) == expected_answer);

    given_prices = {1, 3, 7, 5, 10, 3};
    given_fee = 3;
    expected_answer = 6;
    assert(solution.maxProfit(given_prices, given_fee) == expected_answer);

    return 0;
}

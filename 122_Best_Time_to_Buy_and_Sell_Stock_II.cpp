//#122 Best Time to Buy and Sell Stock II - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i < (int)prices.size(); i++)
        {
            if(prices[i - 1] < prices[i])
                result += prices[i] - prices[i - 1];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_prices = {7, 1, 5, 3, 6, 4};
    int expected_answer = 7;
    assert(solution.maxProfit(given_prices) == expected_answer);

    given_prices = {7, 6, 4, 3, 1};
    expected_answer = 0;
    assert(solution.maxProfit(given_prices) == expected_answer);

    return 0;
}

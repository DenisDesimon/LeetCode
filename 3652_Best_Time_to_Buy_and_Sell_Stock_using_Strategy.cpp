//#3652 Best Time to Buy and Sell Stock using Strategy - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long result = 0;
        for(int i = 0; i < (int)prices.size(); i++)
            result += prices[i] * strategy[i];
        long long profit = result;
        for(int i = 0; i < k; i++)
        {
            if(i < k / 2)
            {
                profit += prices[i] * strategy[i] * (-1);
            }
            else
            {
                profit += prices[i] * strategy[i] * (-1);
                profit += prices[i];
            }
        }
        result = max(result, profit);
        for(int i = k; i < (int)prices.size(); i++)
        {
            profit += prices[i - k] * strategy[i - k];
            profit += prices[i] * strategy[i] * (-1);
            profit += prices[i];
            profit -= prices[i - k / 2];
            result = max(result, profit);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenPrices = {4, 2, 8};
    vector<int> givenStrategy = {-1, 0, 1};
    int givenK = 2;
    long long expected_answer = 10;
    assert(solution.maxProfit(givenPrices, givenStrategy, givenK) == expected_answer);

    givenPrices = {5, 4, 3};
    givenK = 2;
    givenStrategy = {1, 1, 0};
    expected_answer = 9;
    assert(solution.maxProfit(givenPrices, givenStrategy, givenK) == expected_answer);

    return 0;
}

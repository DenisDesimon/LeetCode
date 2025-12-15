//#2110 Number of Smooth Descent Periods of a Stock - https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = prices.size();
        long long count = 1;
        for(int i = 1; i < (int)prices.size(); i++)
        {
            if(prices[i] != prices[i - 1] - 1)
            {
                result += count * (count - 1) / 2;
                count = 1;
            }
            else
                count++;

        }
        result += count * (count - 1) / 2;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenPrices = {3, 2, 1, 4};
    int expectedAnswer = 7;
    assert(solution.getDescentPeriods(givenPrices) == expectedAnswer);

    givenPrices = {8, 6 ,7, 7};
    expectedAnswer = 4;
    assert(solution.getDescentPeriods(givenPrices) == expectedAnswer);

    return 0;
}

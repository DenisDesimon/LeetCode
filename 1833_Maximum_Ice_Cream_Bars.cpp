//#1833 Maximum Ice Cream Bars - https://leetcode.com/problems/maximum-ice-cream-bars/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count[500001] = {0};
        for(auto &cost : costs)
        {
            count[cost]++;
        }
        int result = 0;
        for(int price = 1; price < 500001 && coins >= price; price++)
        {
            if(!count[price])
                continue;
            int curIceCreams = min(count[price], coins / price);
            result += curIceCreams;
            coins -= curIceCreams * price;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCosts = {1, 3, 2, 4, 1};
    int givenCoins = 7;
    int expectedAnswer = 4;
    assert(solution.maxIceCream(givenCosts, givenCoins) == expectedAnswer);

    givenCosts = {1, 6, 3, 1, 2, 5};
    givenCoins = 20;
    expectedAnswer = 6;
    assert(solution.maxIceCream(givenCosts, givenCoins) == expectedAnswer);

    return 0;
}

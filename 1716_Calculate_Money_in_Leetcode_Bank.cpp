//#1716 Calculate Money in Leetcode Bank - https://leetcode.com/problems/calculate-money-in-leetcode-bank/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int fullWeekEarned = weeks * (28 * 2 + 7 * (weeks - 1)) / 2;
        int daysRemainEarn = days * (2 * (1 + weeks) + days - 1) / 2 ;
        return fullWeekEarned + daysRemainEarn;
    }
};

int main()
{
    Solution solution;
    int givenN = 10;
    int expectedAnswer = 37;
    assert(solution.totalMoney(givenN) == expectedAnswer);

    givenN = 20;
    expectedAnswer = 96;
    assert(solution.totalMoney(givenN) == expectedAnswer);

    return 0;
}

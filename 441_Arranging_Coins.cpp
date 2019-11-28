//#441 Arranging Coins - https://leetcode.com/problems/arranging-coins/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        double num = n;
        return (int)(-0.5 + sqrt(0.25 + 2 * num));
    }
};

int main()
{
    Solution solution;
    int given_n = 5;
    int expected_answer = 2;
    assert(solution.arrangeCoins(given_n) == expected_answer);

    given_n = 8;
    expected_answer = 3;
    assert(solution.arrangeCoins(given_n) == expected_answer);

    return 0;
}

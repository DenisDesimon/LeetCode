//#29 Divide Two Integers - https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if(divisor == 1)
            return dividend;
        bool is_minus = (dividend < 0) ^ (divisor < 0);
        long long x = dividend;
        long long y = divisor;
        x = abs(x);
        y = abs(y);
        int result = 0;
        int k = 31;
        while(x >= y)
        {
            while((y << k) > x)
                k--;
            x -= y << k;
            result += (int)(1 << k);
        }
        return is_minus ? -result : result;
    }
};

int main()
{
    Solution solution;
    int given_dividend = -2147483648;
    int given_divisor = 1;
    int expected_answer = -2147483648;
    assert(solution.divide(given_dividend, given_divisor) == expected_answer);

    given_dividend = 10;
    given_divisor = 3;
    expected_answer = 3;
    assert(solution.divide(given_dividend, given_divisor) == expected_answer);

    return 0;
}

//50 Pow(x, n) - https://leetcode.com/problems/powx-n/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double result = 1;
        if(power < 0)
        {
            power = - power;
            x = 1 / x;
        }
        while(power > 0)
        {
            if(power & 1)
                result *= x;
            power >>= 1, x *= x;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    double given_x = 2.00000;
    int given_n = 10;
    double expected_answer = 1024.00000;
    assert(solution.myPow(given_x, given_n) == expected_answer);

    given_x = 2.00000;
    given_n = -2;
    expected_answer = 0.25000;
    assert(solution.myPow(given_x, given_n) == expected_answer);

    return 0;
}

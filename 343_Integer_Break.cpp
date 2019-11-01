//#343 Integer Break - https://leetcode.com/problems/integer-break/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        else if (n % 3 == 0)
            return pow(3, n / 3);
        else if (n % 3 == 2)
            return pow(3, n / 3) * 2;
        else
            return pow(3, n / 3 - 1) * 4;
    }
};

int main()
{
    Solution solution;
    int given_n = 10;
    int expected_answer = 36;
    assert(solution.integerBreak(given_n) == expected_answer);

    given_n = 18;
    expected_answer = 729;
    assert(solution.integerBreak(given_n) == expected_answer);

    return 0;
}

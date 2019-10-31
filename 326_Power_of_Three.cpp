//#326 Power of Three - https://leetcode.com/problems/power-of-three/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)
            return false;
        double result = log10(n)/log10(3);
        return result - (int)result == 0;
    }
};

int main()
{
    Solution solution;
    int given_n = 27;
    bool expected_answer = true;
    assert(solution.isPowerOfThree(given_n) == expected_answer);

    given_n = 243;
    expected_answer = true;
    assert(solution.isPowerOfThree(given_n) == expected_answer);

    return 0;
}

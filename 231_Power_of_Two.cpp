//#231 Power of Two - https://leetcode.com/problems/power-of-two/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == INT_MIN)
            return false;
        if(n == 0)
            return false;
        return !(n & (n - 1));
    }
};

int main()
{
    Solution solution;
    int given_n = INT_MIN;
    bool expected_answer = false;
    assert(solution.isPowerOfTwo(given_n) == expected_answer);

    given_n = 256;
    expected_answer = true;
    assert(solution.isPowerOfTwo(given_n) == expected_answer);

    return 0;
}

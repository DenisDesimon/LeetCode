//#190 Reverse Bits - https://leetcode.com/problems/reverse-bits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        while(n)
        {
            result |= 1 << (31 - __builtin_ctz(n));
            n &= n - 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    uint32_t given_n = 43261596;
    uint32_t expected_answer = 964176192;
    assert(solution.reverseBits(given_n) == expected_answer);

    given_n = 4294967293;
    expected_answer = 3221225471;
    assert(solution.reverseBits(given_n) == expected_answer);

    return 0;
}

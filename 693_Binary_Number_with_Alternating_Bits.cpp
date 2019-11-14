//#693 Binary Number with Alternating Bits - https://leetcode.com/problems/binary-number-with-alternating-bits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last_bit = n % 2;
        n /= 2;
        while(n)
        {
            if(last_bit == n % 2)
                return false;
            last_bit = n % 2;
            n /= 2;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int given_n = 5;
    bool expected_answer = true;
    assert(solution.hasAlternatingBits(given_n) == expected_answer);

    given_n = 4;
    expected_answer = false;
    assert(solution.hasAlternatingBits(given_n) == expected_answer);

    return 0;
}

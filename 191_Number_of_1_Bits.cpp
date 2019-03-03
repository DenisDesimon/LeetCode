//#191 Number of 1 Bits - https://leetcode.com/problems/number-of-1-bits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum_ones = 0;
        while(n)
        {
            sum_ones++;
            n &= (n-1);
        }
        return sum_ones;
    }

};
int main()
{
    Solution solution;
    int given_num = 3;
    int expected_answer = 2;
    assert(solution.hammingWeight(given_num) == expected_answer);

    given_num = 127;
    expected_answer = 7;
    assert(solution.hammingWeight(given_num) == expected_answer);

    return 0;
}

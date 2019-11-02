//#371 Sum of Two Integers - https://leetcode.com/problems/sum-of-two-integers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main()
{
    Solution solution;
    int given_a = 1, given_b = 3;
    int expected_answer = 4;
    assert(solution.getSum(given_a, given_b) == expected_answer);

    given_a = 1, given_b = -1;
    expected_answer = 0;
    assert(solution.getSum(given_a, given_b) == expected_answer);

    return 0;
}

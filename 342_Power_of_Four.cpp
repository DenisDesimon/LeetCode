//#342 Power of Fours - https://leetcode.com/problems/power-of-four/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        int power = 0b1010101010101010101010101010101;
        if(num < 0 || num & (num - 1))
            return false;
        return num & power;
    }
};

int main()
{
    Solution solution;
    int given_num = 32;
    bool expected_answer = false;
    assert(solution.isPowerOfFour(given_num) == expected_answer);

    given_num = 64;
    expected_answer = true;
    assert(solution.isPowerOfFour(given_num) == expected_answer);

    return 0;
}

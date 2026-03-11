//#1009 Complement of Base 10 Integer - https://leetcode.com/problems/complement-of-base-10-integer/
#include <iostream>
#include <cassert>


class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n)
            mask = (mask << 1) + 1;
        return mask ^ n;
    }
};

using namespace std;

int main()
{
    Solution solution;
    int givenN = 5;
    int expectedAnswer = 2;
    assert(solution.bitwiseComplement(givenN) == expectedAnswer);

    givenN = 10;
    expectedAnswer = 5;
    assert(solution.bitwiseComplement(givenN) == expectedAnswer);

    return 0;
}

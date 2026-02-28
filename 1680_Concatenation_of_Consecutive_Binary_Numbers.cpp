//#1680 Concatenation of Consecutive Binary Numbers - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long result = 0;
        for(int num = 1; num <= n; num++)
        {
            int shift = 32 - __builtin_clz(num);
            result = ((result << shift) % mod + num) % mod;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 12;
    int expectedAnswer = 505379714;
    assert(solution.concatenatedBinary(givenN) == expectedAnswer);

    givenN = 3;
    expectedAnswer = 27;
    assert(solution.concatenatedBinary(givenN) == expectedAnswer);

    return 0;
}

//#868 Binary Gap - https://leetcode.com/problems/binary-gap/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        n >>= __builtin_ctz(n) + 1;
        while(n)
        {
            int gap = __builtin_ctz(n);
            result = max(result, gap + 1);
            n >>= gap + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 22;
    int expectedAnswer = 2;
    assert(solution.binaryGap(givenN) == expectedAnswer);

    givenN = 8;
    expectedAnswer = 0;
    assert(solution.binaryGap(givenN) == expectedAnswer);

    return 0;
}

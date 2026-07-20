//#3993 Maximum Value of an Alternating Sequence - https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1)
            return s;
        long long startFromBot = (long long)n / 2 * (m - 1) + 1;
        long long startFromTop = (long long)n / 2 * (m - 1);
        return s + max(startFromBot, startFromTop);
    }
};

int main()
{
    Solution solution;
    int givenN = 4;
    int givenS = 3;
    int givenM = 5;
    int expectedAnswer = 12;
    assert(solution.maximumValue(givenN, givenS, givenM) == expectedAnswer);

    givenN = 2;
    givenS = 4;
    givenM = 3;
    expectedAnswer = 7;
    assert(solution.maximumValue(givenN, givenS, givenM) == expectedAnswer);

    return 0;
}

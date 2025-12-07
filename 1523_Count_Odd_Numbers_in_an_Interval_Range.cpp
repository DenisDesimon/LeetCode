//#1523 Count Odd Numbers in an Interval Range - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};

int main()
{
    Solution solution;
    int givenLow = 3;
    int givenHigh = 7;
    int expectedAnswer = 3;
    assert(solution.countOdds(givenLow, givenHigh) == expectedAnswer);

    givenLow = 8;
    givenHigh = 10;
    expectedAnswer = 1;
    assert(solution.countOdds(givenLow, givenHigh) == expectedAnswer);

    return 0;
}

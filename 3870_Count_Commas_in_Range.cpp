//#3870 Count Commas in Range - https://leetcode.com/problems/count-commas-in-range/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return max(0, n - (int)1e3 + 1);
    }
};

int main()
{
    Solution solution;
    int givenN = 1002;
    int expectedAnswer = 3;
    assert(solution.countCommas(givenN) == expectedAnswer);

    givenN = 10068;
    expectedAnswer = 9069;
    assert(solution.countCommas(givenN) == expectedAnswer);


    return 0;
}

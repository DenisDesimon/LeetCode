//#3871 Count Commas in Range II - https://leetcode.com/problems/count-commas-in-range-ii/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;
        result += max(0LL, n - 999);
        result += max(0LL, n - 999999);
        result += max(0LL, n - 999999999LL);
        result += max(0LL, n - 999999999999LL);
        result += max(0LL, n - 999999999999999LL);
        return result;
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

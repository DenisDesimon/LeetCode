//#70 Climbing Stairs - https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

int main()
{
    Solution solution;
    int given_n = 5;
    int expected_answer = 8;
    assert(solution.climbStairs(given_n) == expected_answer);

    given_n = 35;
    expected_answer = 14930352;
    assert(solution.climbStairs(given_n) == expected_answer);

    return 0;
}

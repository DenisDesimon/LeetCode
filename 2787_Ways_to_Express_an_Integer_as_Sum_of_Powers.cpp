//#2787 Ways to Express an Integer as Sum of Powers - https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp.front() = 1;
        for(int i = 1; i <= n; i++)
        {
            long long prevSummand = pow(i, x);
            for(int j = n; j >= prevSummand; j--)
            {
                dp[j] = (dp[j] + dp[j - prevSummand]) % mod;
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    int givenN = 10;
    int givenX = 2;
    int expectedAnswer = 1;
    assert(solution.numberOfWays(givenN, givenX) == expectedAnswer);

    givenN = 4;
    givenX = 1;
    expectedAnswer = 2;
    assert(solution.numberOfWays(givenN, givenX) == expectedAnswer);

    return 0;
}

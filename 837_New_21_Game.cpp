//#837 New 21 Game - https://leetcode.com/problems/new-21-game/
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double sumProb = k == 0 ? 0 : 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = sumProb / maxPts;
            if(i < k)
                sumProb += dp[i];
            if(i - maxPts >= 0 && i - maxPts < k)
                sumProb -= dp[i - maxPts];
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};

int main()
{
    Solution solution;
    int givenN = 21;
    int givenK = 17;
    int givenMaxPts = 10;
    double expectedAnswer = 0.73278;
    assert(round(solution.new21Game(givenN, givenK, givenMaxPts) * 100000) / 100000 == expectedAnswer);

    givenN = 5341;
    givenK = 5198;
    givenMaxPts = 9993;
    expectedAnswer = 0.02424;
    assert(round(solution.new21Game(givenN, givenK, givenMaxPts) * 100000) / 100000 == expectedAnswer);

    return 0;
}

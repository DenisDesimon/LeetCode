//#1621 Number of Sets of K Non-Overlapping Line Segments - https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n, 1);
        vector<int> prefix(n);
        int MOD = 1e9 + 7;
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + dp[i - 1];
        dp.front() = 0;
        for(int segments = 1; segments <= k; segments++)
        {
            for(int i = 1; i < n; i++)
                dp[i] = (dp[i - 1] + prefix[i]) % MOD;
            for(int i = 1; i < n; i++)
                prefix[i] = (prefix[i - 1] + dp[i - 1]) % MOD;
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    int givenN = 4;
    int givenK = 2;
    int expectedAnswer = 5;
    assert(solution.numberOfSets(givenN, givenK) == expectedAnswer);

    givenN = 30;
    givenK = 7;
    expectedAnswer = 796297179;
    assert(solution.numberOfSets(givenN, givenK) == expectedAnswer);


    return 0;
}

//#940 Distinct Subsequences II - https://leetcode.com/problems/distinct-subsequences-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp.front() = 1;
        int MOD = 1e9 + 7;
        vector<int> lastIdx(26, -1);
        for(int i = 0; i < n; i++)
        {
            int letter = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % MOD;
            if(lastIdx[letter] != -1)
                dp[i + 1] = (dp[i + 1] - dp[lastIdx[letter]] + MOD) % MOD;
            lastIdx[letter] = i;
        }
        dp.back() = (dp.back() -1 + MOD) % MOD;
        return dp.back();
    }
};

int main()
{
    Solution solution;
    string givenS = "abc";
    int expectedAnswer = 7;
    assert(solution.distinctSubseqII(givenS) == expectedAnswer);

    givenS = "aba";
    expectedAnswer = 6;
    assert(solution.distinctSubseqII(givenS) == expectedAnswer);


    return 0;
}

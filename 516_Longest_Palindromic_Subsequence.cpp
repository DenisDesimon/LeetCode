//#516 Longest Palindromic Subsequence - https://leetcode.com/problems/longest-palindromic-subsequence/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution solution;
    string given_s = "bbbab";
    int expected_answer = 4;
    assert(solution.longestPalindromeSubseq(given_s) == expected_answer);

    given_s = "bbabb";
    expected_answer = 5;
    assert(solution.longestPalindromeSubseq(given_s) == expected_answer);

    return 0;
}

//44 Wildcard Matching - https://leetcode.com/problems/wildcard-matching/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int dp[n + 1][m + 1] = {};
        dp[n][m] = true;
        for(int i = n; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                bool cur_match = i < n && (s[i] == p[j] || p[j] == '?');
                if(p[j] == '*')
                {
                    dp[i][j] = dp[i][j + 1] || (i < n && dp[i + 1][j]);
                }
                else
                    dp[i][j] = cur_match && i < n && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution solution;
    string given_s = "aa";
    string given_p = "*";
    bool expected_answer = true;
    assert(solution.isMatch(given_s, given_p) == expected_answer);

    given_s = "adceb";
    given_p = "*a*b";
    expected_answer = true;
    assert(solution.isMatch(given_s, given_p) == expected_answer);

    return 0;
}

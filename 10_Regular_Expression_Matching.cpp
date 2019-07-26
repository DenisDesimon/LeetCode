//#10 Regular Expression Matching - https://leetcode.com/problems/regular-expression-matching/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        bool dp[n + 1][m + 1] = {};
        dp[n][m] = true;
        for(int i = n; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                bool first_match = (i < n && (s[i] == p[j] || p[j] == '.'));
                if(j + 1 < m && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution solution;
    string given_s = "acaabbaccbbacaabbbb";
    string given_p = "a*.*b*.*a*aa*a*";
    bool expected_answer = false;
    assert(solution.isMatch(given_s, given_p) == expected_answer);

    given_s = "aaaa";
    given_p = "a*a";
    expected_answer = true;
    assert(solution.isMatch(given_s, given_p) == expected_answer);

    return 0;
}

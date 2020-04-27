//#1143 Longest Common Subsequence - https://leetcode.com/problems/longest-common-subsequence/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 0; i < (int)text1.size(); i++)
        {
            for(int j = 0; j < (int)text2.size(); j++)
            {
                if(text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution solution;
    string given_text1 = "abcde";
    string given_text2 = "ace";
    int expected_answer = 3;
    assert(solution.longestCommonSubsequence(given_text1, given_text2) == expected_answer);

    given_text1 = "abc";
    given_text2 = "def";
    expected_answer = 0;
    assert(solution.longestCommonSubsequence(given_text1, given_text2) == expected_answer);

    return 0;
}

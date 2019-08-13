//#97 Interleaving String - https://leetcode.com/problems/interleaving-string/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != (int)s3.size())
            return false;
        vector<bool> dp(m + 1);
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < m + 1; j++)
            {
                if(i == 0 && j == 0)
                    dp[j] = true;
                else if(i == 0)
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
                else
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m];
    }
};

int main()
{
    Solution solution;
    string given_s1 = "a";
    string given_s2 = "";
    string given_s3 = "a";
    bool expected_answer = true;
    assert(solution.isInterleave(given_s1, given_s2, given_s3) == expected_answer);

    given_s1 = "aabcc";
    given_s2 = "dbbca";
    given_s3 = "aadbbcbcac";
    expected_answer = true;
    assert(solution.isInterleave(given_s1, given_s2, given_s3) == expected_answer);

    return 0;
}

//#132 Palindrome Partitioning II - https://leetcode.com/problems/palindrome-partitioning-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size() + 1);
        for(int i = 0; i <= (int)s.size(); i++)
            dp[i] = i - 1;
        for(int i = 0; i < (int)s.size(); i++)
        {
            for(int j = 0; i - j >= 0 && i + j < (int)s.size() && s[i + j] == s[i - j]; j++)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);

            for(int j = 0; i - j - 1 >= 0 && i + j < (int)s.size() && s[i + j] == s[i - j - 1]; j++)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j - 1] + 1);
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution solution;
    string given_s = "ababbbabbaba";
    int expected_answer = 3;
    assert(solution.minCut(given_s) == expected_answer);

    given_s = "cabababcbc";
    expected_answer = 3;
    assert(solution.minCut(given_s) == expected_answer);

    return 0;
}

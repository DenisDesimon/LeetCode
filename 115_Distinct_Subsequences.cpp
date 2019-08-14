//#115 Distinct Subsequences - https://leetcode.com/problems/distinct-subsequences/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty())
            return 0;
        vector<unsigned int> dp(t.size() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < (int)s.size(); i++)
        {
            for(int j = t.size(); j >= 1; j--)
            {
                if(s[i] == t[j - 1])
                    dp[j] += dp[j - 1];
            }
        }
        return dp[t.size()];
    }
};

int main()
{
    Solution solution;
    string given_s = "rabbbit";
    string given_t = "rabbit";
    int expected_answer = 3;
    assert(solution.numDistinct(given_s, given_t) == expected_answer);

    given_s = "babgbag";
    given_t = "bag";
    expected_answer = 5;
    assert(solution.numDistinct(given_s, given_t) == expected_answer);

    return 0;
}

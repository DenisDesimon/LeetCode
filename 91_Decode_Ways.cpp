//#91 Decode Ways - https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= n; i++)
        {
            int digit = s[i - 1] - '0';
            int num = stoi(s.substr(i - 2, 2));
            if(digit >= 1 && digit <= 9)
                dp[i] += dp[i - 1];
            if(num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    string given_s = "110";
    int expected_answer = 1;
    assert(solution.numDecodings(given_s) == expected_answer);

    given_s = "25252";
    expected_answer = 4;
    assert(solution.numDecodings(given_s) == expected_answer);

    return 0;
}

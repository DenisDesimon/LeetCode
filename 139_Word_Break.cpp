//#139 Word Break - https://leetcode.com/problems/word-break/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= (int)s.size(); i++)
        {
            if(!dp[i - 1])
                continue;
            for(int j = 0; j < (int)wordDict.size(); j++)
            {
                if(i - 1 + wordDict[j].size() > s.size())
                    continue;
                if(s.substr(i - 1, wordDict[j].size()) == wordDict[j])
                    dp[i - 1 + wordDict[j].size()] = true;
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution solution;
    string given_s = "leetcode";
    vector<string> given_dictionary = {"leet", "code"};
    bool expected_answer = true;
    assert(solution.wordBreak(given_s, given_dictionary) == expected_answer);

    given_s = "catsandog";
    given_dictionary = {"cats", "dog", "sand", "and", "cat"};
    expected_answer = false;
    assert(solution.wordBreak(given_s, given_dictionary) == expected_answer);

    return 0;
}

//#140 Word Break II - https://leetcode.com/problems/word-break-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    vector<string> get_result(vector<vector<int>> dp, int idx, vector<string>& wordDict){
        if(idx == 0)
            return {{}};
        vector<string> result;
        for(auto &index : dp[idx])
        {
            auto sub_res = get_result(dp, idx - wordDict[index].size(), wordDict);
            for(auto word : sub_res)
            {
                if(word.empty())
                    result.push_back(word + wordDict[index]);
                else
                    result.push_back(word + " " + wordDict[index]);
            }
        }
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size() + 1);
        vector<string> result;
        dp[0].push_back(0);
        for(int i = 1; i <= (int)s.size(); i++)
        {
            if(dp[i - 1].empty())
                continue;
            for(int j = 0; j < (int)wordDict.size(); j++)
            {
                if(i - 1 + (int)wordDict[j].size() > (int)s.size())
                    continue;
                if(s.substr(i - 1, wordDict[j].size()) == wordDict[j])
                    dp[i- 1 + wordDict[j].size()].push_back(j);
            }
        }
        return get_result(dp, s.size(), wordDict);
    }
};

int main()
{
    Solution solution;
    string given_s = "catsanddog";
    vector<string> given_wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> expected_result = {"cat sand dog", "cats and dog"};
    assert(solution.wordBreak(given_s, given_wordDict) == expected_result);

    given_s = "catsandog";
    given_wordDict = {"cats", "dog", "sand", "and", "cat"};
    expected_result = {};
    assert(solution.wordBreak(given_s, given_wordDict) == expected_result);

    return 0;
}

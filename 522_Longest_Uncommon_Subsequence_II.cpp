//#522 Longest Uncommon Subsequence II - https://leetcode.com/problems/longest-uncommon-subsequence-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> hash;
        int result = -1;
        for(auto& str : strs)
        {
            hash[str]++;
        }
        for(auto& word : hash)
        {
            if(word.second == 1)
            {
                if((int)word.first.size() > result)
                {
                    int i = 0;
                    for(; i < (int)strs.size(); i++)
                    {
                        if(strs[i] == word.first)
                            continue;
                        int idx = 0;
                        for(auto& ch : strs[i])
                        {
                            if(ch == word.first[idx])
                            {
                                idx++;
                                if(idx == (int)word.first.size())
                                    break;
                            }
                        }
                        if(idx == (int)word.first.size())
                            break;
                    }
                    if(i == (int)strs.size())
                        result = word.first.size();
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_strs = {"aabbcc", "aabbcc", "b", "bc"};
    int expected_answer = -1;
    assert(solution.findLUSlength(given_strs) == expected_answer);

    given_strs = {"aba", "cdc", "eae"};
    expected_answer = 3;
    assert(solution.findLUSlength(given_strs) == expected_answer);

    return 0;
}

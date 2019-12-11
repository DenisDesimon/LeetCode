//#524 Longest Word in Dictionary through Deleting - https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result;
        if(s.empty() || d.empty())
            return result;
        for(auto& word : d)
        {
            if(result.size() > word.size())
                continue;
            int idx = 0;
            for(int i = 0; i < (int)s.size() && idx < (int)word.size(); i++)
            {
                if(s[i] == word[idx])
                    idx++;
            }
            if(idx == (int)word.size())
            {
                if(result.size() != word.size())
                {
                    result = word;
                }
                else
                    result = min(result, word);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_d = {"a", "b", "c"};
    string given_s = "abpcplea";
    string expected_answer = "a";
    assert(solution.findLongestWord(given_s, given_d) == expected_answer);

    given_d = {"ale", "apple", "monkey", "plea"};
    given_s = "abpcplea";
    expected_answer = "apple";
    assert(solution.findLongestWord(given_s, given_d) == expected_answer);

    return 0;
}

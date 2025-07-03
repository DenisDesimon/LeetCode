//#2900 Longest Unequal Adjacent Groups Subsequence I - https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result(1, words.front());
        int prev = groups.front();
        for(int i = 1; i < (int)groups.size(); i++)
        {
            if(groups[i] != prev)
            {
                prev = groups[i];
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string>  given_words = {"a", "b", "c", "d"};
    vector<int> given_groups = {1, 0, 1, 1};
    vector<string> expected_answer = {"a", "b", "c"};
    assert(solution.getLongestSubsequence(given_words, given_groups) == expected_answer);

    given_words = {"e", "a", "b"};
    given_groups = {0, 0, 1};
    expected_answer = {"e", "b"};
    assert(solution.getLongestSubsequence(given_words, given_groups) == expected_answer);

    return 0;
}

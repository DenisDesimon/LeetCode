//#1930 Unique Length-3 Palindromic Subsequences - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> letterPrev(26, vector<int>(27));
        vector<int> letterMax(26);
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int cur = s[i] - 'a';
            letterMax[cur] = letterPrev[cur][26] ? accumulate(letterPrev[cur].begin(), letterPrev[cur].end(), -1) : 0;
            for(int j = 0; j < 26; j++)
            {
                if(letterPrev[j][26])
                    letterPrev[j][cur] = 1;
            }
            letterPrev[cur][26] = 1;
        }
        return accumulate(letterMax.begin(), letterMax.end(), 0);
    }
};

int main()
{
    Solution solution;
    string givenS = "aabca";
    int expectedAnswer = 3;
    assert(solution.countPalindromicSubsequence(givenS) == expectedAnswer);

    givenS = "bbcbaba";
    expectedAnswer = 4;
    assert(solution.countPalindromicSubsequence(givenS) == expectedAnswer);

    return 0;
}

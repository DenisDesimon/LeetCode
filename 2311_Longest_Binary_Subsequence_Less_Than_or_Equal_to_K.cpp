//#2311 Longest Binary Subsequence Less Than or Equal to K - https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        int countBits = 32 - __builtin_clz(k);
        int rightBits = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[s.size() - 1 - i] == '1')
            {
                if(i < countBits  && rightBits + (1 << i) <= k)
                {
                    rightBits += 1 << i;
                    result++;
                }
            }
            else
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "1001010";
    int given_k = 5;
    int expected_answer = 5;
    assert(solution.longestSubsequence(given_s, given_k) == expected_answer);

    given_s = "00101001";
    given_k = 1;
    expected_answer = 6;
    assert(solution.longestSubsequence(given_s, given_k) == expected_answer);

    return 0;
}

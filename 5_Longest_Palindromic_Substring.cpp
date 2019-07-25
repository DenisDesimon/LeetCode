//#5 Longest Palindromic Substring - https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
    int length(string s, int start, int end){
        while(start >= 0 && end < (int)s.size() && s[start] == s[end])
        {
            start--, end++;
        }
        return end - start - 1;

    }
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            int length1 = length(s, i, i + 1);
            int length2 = length(s, i, i);
            int max_length = max(length1, length2);
            if(max_length > end - start + 1)
            {
                start = i - (max_length - 1) / 2;
                end = i + max_length / 2;
            }
        }
        return string(s, start, end - start + 1);
    }
};

int main()
{
    Solution solution;
    string given_s = "babad";
    string expected_answer = "bab";
    assert(solution.longestPalindrome(given_s) == expected_answer);

    given_s = "cbbd";
    expected_answer = "bb";
    assert(solution.longestPalindrome(given_s) == expected_answer);

    return 0;
}

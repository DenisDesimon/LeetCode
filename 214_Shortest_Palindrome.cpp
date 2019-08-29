//#214 Shortest Palindrome - https://leetcode.com/problems/shortest-palindrome/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s)
    {
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        string kmp = s + '#' + reverse_s;
        vector<int> prefix(kmp.size(), 0);
        for(int i = 1; i < (int)kmp.size(); i++)
        {
            int length = prefix[i - 1];
            while(length > 0 && kmp[i] != kmp[length])
                length = prefix[length - 1];
            if(kmp[length] == kmp[i])
                length++;
            prefix[i] = length;
        }
        return reverse_s.substr(0, s.size() - prefix.back()) + s;
    }
};

int main()
{
    Solution solution;
    string given_s = "aacecaaa";
    string expected_answer = "aaacecaaa";
    assert(solution.shortestPalindrome(given_s) == expected_answer);

    given_s = "abcd";
    expected_answer = "dcbabcd";
    assert(solution.shortestPalindrome(given_s) == expected_answer);

    return 0;
}

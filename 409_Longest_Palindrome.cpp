//#409 Longest Palindrome - https://leetcode.com/problems/longest-palindrome/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int alphobet[58] = {0};
        for(auto& ch : s)
        {
            alphobet[ch - 'A']++;
        }
        int result = 0;
        for(int i = 0; i < 58; i++)
        {
            result += alphobet[i] / 2 * 2;
            if(result % 2 == 0 && alphobet[i] % 2 == 1)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "abccccdd";
    int expected_answer = 7;
    assert(solution.longestPalindrome(given_s) == expected_answer);

    given_s = "aaabbbcccfff";
    expected_answer = 9;
    assert(solution.longestPalindrome(given_s) == expected_answer);

    return 0;
}

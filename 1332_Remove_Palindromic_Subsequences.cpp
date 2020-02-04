//#1332 Remove Palindromic Subsequences - https://leetcode.com/problems/remove-palindromic-subsequences/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        if(s == string(s.rbegin(), s.rend()))
            return 1;
        return 2;
    }
};

int main()
{
    Solution solution;
    string given_s = "baabb";
    int expected_answer = 2;
    assert(solution.removePalindromeSub(given_s) == expected_answer);

    given_s = "abba";
    expected_answer = 1;
    assert(solution.removePalindromeSub(given_s) == expected_answer);

    return 0;
}

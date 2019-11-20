//#459 Repeated Substring Pattern - https://leetcode.com/problems/repeated-substring-pattern/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string check = s + s;
        check.front() = check.back() = '#';
        return check.find(s) != string::npos;
    }
};

int main()
{
    Solution solution;
    string given_s = "abcabcabcabc";
    bool expected_answer = true;
    assert(solution.repeatedSubstringPattern(given_s) == expected_answer);

    given_s = "abad";
    expected_answer = false;
    assert(solution.repeatedSubstringPattern(given_s) == expected_answer);

    return 0;
}

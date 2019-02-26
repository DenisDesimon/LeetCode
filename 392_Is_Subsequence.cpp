//#392 Is Subsequence - https://leetcode.com/problems/is-subsequence/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0)
            return true;
        int pos = 0;
        for(int i = 0; i != (int)t.size(); i++)
        {
            if(s[pos] == t[i])
                pos++;
            if(pos == (int)s.size())
                return true;
        }

        return false;
    }
};

int main()
{
    Solution solution;
    string given_string1 = "";
    string given_string2 = "";
    bool expected_answer = true;
    assert(solution.isSubsequence(given_string1, given_string2) == expected_answer);

    given_string1 = "abc";
    given_string2 = "ahgdc";
    expected_answer = false;
    assert(solution.isSubsequence(given_string1, given_string2) == expected_answer);

    return 0;
}

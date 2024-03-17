//#3084 Count Substrings Starting and Ending with Given Character - https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        for(auto & symb : s)
        {
            if(symb == c)
                count++;
        }
        return count * (count + 1) / 2;
    }
};

int main()
{
    Solution solution;
    string given_s = "zzz";
    char given_c = 'z';
    long long expected_answer = 6;
    assert(solution.countSubstrings(given_s, given_c) == expected_answer);

    given_s = "abada";
    given_c = 'a';
    expected_answer = 6;
    assert(solution.countSubstrings(given_s, given_c) == expected_answer);

    return 0;
}

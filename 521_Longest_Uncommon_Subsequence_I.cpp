//#521 Longest Uncommon Subsequence I - https://leetcode.com/problems/longest-uncommon-subsequence-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        else
            return max(a.size(), b.size());
    }
};

int main()
{
    Solution solution;
    string given_a = "abc";
    string given_b = "cdc";
    int expected_answer = 3;
    assert(solution.findLUSlength(given_a, given_b) == expected_answer);

    given_a = "abc";
    given_b = "abc23";
    expected_answer = 5;
    assert(solution.findLUSlength(given_a, given_b) == expected_answer);

    return 0;
}

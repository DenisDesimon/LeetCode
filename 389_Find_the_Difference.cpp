//#389 Find the Difference - https://leetcode.com/problems/find-the-difference/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for(auto ch : s)
            count[ch - 'a']++;
        for(auto ch : t)
            count[ch - 'a']--;
        for(int i = 0; i < 26; i++)
        {
            if(count[i] == -1)
                return 'a' + i;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    string given_s = "abcd";
    string given_t = "abcde";
    char expected_answer = 'e';
    assert(solution.findTheDifference(given_s, given_t) == expected_answer);

    given_s = "a";
    given_t = "aa";
    expected_answer = 'a';
    assert(solution.findTheDifference(given_s, given_t) == expected_answer);

    return 0;
}

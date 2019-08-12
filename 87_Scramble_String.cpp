//#87 Scramble String - https://leetcode.com/problems/scramble-string/
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n != (int)s2.size())
            return false;
        if(s1 == s2)
            return true;
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if(temp1 != temp2)
            return false;
        for(int i = 1; i < n; i++)
        {
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
               (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))))
                    return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string given_s1 = "great";
    string given_s2 = "rgeat";
    bool expected_answer = true;
    assert(solution.isScramble(given_s1, given_s2) == expected_answer);

    given_s1 = "abcdefghijklmnopq";
    given_s2 = "efghijklmnopqcadb";
    expected_answer = false;
    assert(solution.isScramble(given_s1, given_s2) == expected_answer);

    return 0;
}

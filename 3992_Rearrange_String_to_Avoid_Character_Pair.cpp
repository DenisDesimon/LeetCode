//#3992 Rearrange String to Avoid Character Pair - https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int pos = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == y)
            {
                swap(s[i], s[pos]);
                pos++;
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string givenS = "aabc";
    char givenX = 'a';
    char givenY = 'c';
    string expectedAnswer = "caba";
    assert(solution.rearrangeString(givenS, givenX, givenY) == expectedAnswer);

    givenS = "dcab";
    givenX = 'd';
    givenY = 'b';
    expectedAnswer = "bcad";
    assert(solution.rearrangeString(givenS, givenX, givenY) == expectedAnswer);

    return 0;
}

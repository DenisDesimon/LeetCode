//#3517 Smallest Palindromic Rearrangement I - https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int count[26] = {0};
        for(auto &letter : s)
            count[letter - 'a']++;
        int n = s.size();
        int pos = 0;
        for(int i = 0; i < 26; i++)
        {
            if(!count[i])
                continue;
            for(int j = 0; j < count[i] / 2; j++)
            {
                s[pos] = 'a' + i;
                s[n - 1 - pos] = 'a' + i;
                pos++;
            }
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string givenS = "babab";
    string expectedAnswer = "abbba";
    assert(solution.smallestPalindrome(givenS) == expectedAnswer);

    givenS = "daccad";
    expectedAnswer = "acddca";
    assert(solution.smallestPalindrome(givenS) == expectedAnswer);

    return 0;
}

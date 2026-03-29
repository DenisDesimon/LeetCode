//#3884 First Matching Character From Both Ends - https://leetcode.com/problems/first-matching-character-from-both-ends/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for(int i = 0; i < n + 1 / 2; i++)
        {
            if(s[i] == s[n - 1 - i])
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string givenS = "abcacbd";
    int expectedAnswer = 1;
    assert(solution.firstMatchingIndex(givenS) == expectedAnswer);

    givenS = "abc";
    expectedAnswer = 1;
    assert(solution.firstMatchingIndex(givenS) == expectedAnswer);

    return 0;
}

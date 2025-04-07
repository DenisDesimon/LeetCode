//#3461 Check If Digits Are Equal in String After Operations I - https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution{
public:
    bool hasSameDigits(string s){
        for(int i = (int)s.size(); i > 2; i--)
        {
            for(int j = 0; j < i - 1; j++)
            {
                s[j] = (s[j] + s[j + 1] - '0') % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};

int main()
{
    Solution solution;
    string givenS = "3902";
    bool expectedAnswer = true;
    assert(solution.hasSameDigits(givenS) == expectedAnswer);

    givenS = "34789";
    expectedAnswer = false;
    assert(solution.hasSameDigits(givenS) == expectedAnswer);

    return 0;
}

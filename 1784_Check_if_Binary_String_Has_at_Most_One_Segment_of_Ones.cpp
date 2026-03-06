//#1784 Check if Binary String Has at Most One Segment of Ones - https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(s[i] - '0' && !(s[i - 1] - '0'))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string givenS = "1001";
    bool expectedAnswer = false;
    assert(solution.checkOnesSegment(givenS) == expectedAnswer);

    givenS = "110";
    expectedAnswer = true;
    assert(solution.checkOnesSegment(givenS) == expectedAnswer);

    return 0;
}

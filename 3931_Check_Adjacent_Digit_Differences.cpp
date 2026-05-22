//#3931 Check Adjacent Digit Differences - https://leetcode.com/problems/check-adjacent-digit-differences/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(abs(s[i] - s[i - 1]) > 2)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string givenS  = "129";
    bool expectedAnswer = false;
    assert(solution.isAdjacentDiffAtMostTwo(givenS) == expectedAnswer);

    givenS  = "132";
    expectedAnswer = true;
    assert(solution.isAdjacentDiffAtMostTwo(givenS) == expectedAnswer);

    return 0;
}

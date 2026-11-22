//#2124 Check if All A's Appears Before All B's - https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool isBstarted = false;
        for(auto &letter : s)
        {
            if(letter == 'b')
                isBstarted = true;
            else if(isBstarted)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string givenS = "aaabbb";
    bool expectedAnswer = true;
    assert(solution.checkString(givenS) == expectedAnswer);

    givenS = "abab";
    expectedAnswer = false;
    assert(solution.checkString(givenS) == expectedAnswer);

    return 0;
}

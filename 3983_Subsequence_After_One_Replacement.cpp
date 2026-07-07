//#3983 Subsequence After One Replacement - https://leetcode.com/problems/subsequence-after-one-replacement/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int countNoReplace = 0, countWithReplace = 0;
        for(int i = 0; i < (int)t.size(); i++)
        {
            if(countNoReplace == n || countWithReplace == n)
                return true;
            if(s[countWithReplace] == t[i])
                countWithReplace++;
            if(s[countNoReplace] == t[i])
                countNoReplace++;
            else
            {
                countWithReplace = max(countWithReplace, countNoReplace + 1);
            }
        }
        return countWithReplace == n;
    }
};

int main()
{
    Solution solution;
    string givenS = "cat";
    string givenT = "chat";
    bool expectedAnswer = true;
    assert(solution.canMakeSubsequence(givenS, givenT) == expectedAnswer);

    givenS = "plane";
    givenT = "apple";
    expectedAnswer = false;
    assert(solution.canMakeSubsequence(givenS, givenT) == expectedAnswer);

    return 0;
}

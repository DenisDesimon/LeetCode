//#3227 Vowels Game in a String  - https://leetcode.com/problems/vowels-game-in-a-string/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto &letter : s)
        {
            if(letter == 'a' || letter =='e' || letter == 'i' || letter == 'o' || letter =='u')
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string givenS = "leetcoder";
    bool expectedAnswer = true;
    assert(solution.doesAliceWin(givenS) == expectedAnswer);

    givenS = "bbcd";
    expectedAnswer = false;
    assert(solution.doesAliceWin(givenS) == expectedAnswer);

    return 0;
}

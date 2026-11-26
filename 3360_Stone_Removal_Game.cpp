//#3360 Stone Removal Game - https://leetcode.com/problems/stone-removal-game/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int turn = 0;
        while(n >= take)
        {
            n -= take--;
            turn ^= 1;
        }
        return turn == 1;
    }
};

int main()
{
    Solution solution;
    int givenN = 12;
    bool expectedAnswer = true;
    assert(solution.canAliceWin(givenN) == expectedAnswer);

    givenN = 1;
    expectedAnswer = false;
    assert(solution.canAliceWin(givenN) == expectedAnswer);

    return 0;
}

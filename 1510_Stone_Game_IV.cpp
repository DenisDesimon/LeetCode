//#1510 Stone Game IV - https://leetcode.com/problems/stone-game-iv/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int MAX_SIZE = 1e5;
bool dp[MAX_SIZE + 1] = {false};

int init = [](){
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if(!dp[i])
        {
            for(int j = 1; i + j * j <= MAX_SIZE; j++)
            {
                dp[i + j * j] = true;
            }
        }
    }
    return 0;
}();
class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp[n];
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    bool expectedAnswer = false;
    assert(solution.winnerSquareGame(givenN) == expectedAnswer);

    givenN = 4;
    expectedAnswer = true;
    assert(solution.winnerSquareGame(givenN) == expectedAnswer);

    return 0;
}

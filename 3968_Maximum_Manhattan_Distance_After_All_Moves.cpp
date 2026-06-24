//#3968 Maximum Manhattan Distance After All Moves - https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int countUnder = 0;
        for(auto &move : moves)
        {
            if(move == 'U')
                y++;
            else if(move == 'D')
                y--;
            else if(move == 'L')
                x--;
            else if(move == 'R')
                x++;
            else
                countUnder++;
        }
        return abs(x) + abs(y) + countUnder;
    }
};

int main()
{
    Solution solution;
    string givenMoves = "L_D_";
    int expectedAnswer = 4;
    assert(solution.maxDistance(givenMoves) == expectedAnswer);

    givenMoves = "U_R";
    expectedAnswer = 3;
    assert(solution.maxDistance(givenMoves) == expectedAnswer);

    return 0;
}

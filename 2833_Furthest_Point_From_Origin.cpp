//#2833 Furthest Point From Origin - https://leetcode.com/problems/furthest-point-from-origin/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0;
        for(auto &move : moves)
        {
            if(move == 'L')
            {
                left++;
                right--;
            }
            else if(move == 'R')
            {
                right++;
                left--;
            }
            else
            {
                right++;
                left++;
            }
        }
        return max(left, right);
    }
};

int main()
{
    Solution solution;
    string givenMoves = "L_RL__R";
    int expectedAnswer = 3;
    assert(solution.furthestDistanceFromOrigin(givenMoves) == expectedAnswer);

    givenMoves = "_R__LL_";
    expectedAnswer = 5;
    assert(solution.furthestDistanceFromOrigin(givenMoves) == expectedAnswer);

    return 0;
}

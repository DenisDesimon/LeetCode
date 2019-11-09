//#657 Robot Return to Origin - https://leetcode.com/problems/robot-return-to-origin/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int updown = 0, leftright = 0;
        for(auto move : moves)
        {
            switch(move)
            {
                case 'R' :
                    leftright++;
                    break;
                case 'L' :
                    leftright--;
                    break;
                case 'U' :
                    updown++;
                    break;
                case 'D' :
                    updown--;
                    break;
            }
        }
        return updown == 0 && leftright == 0;
    }
};

int main()
{
    Solution solution;
    string given_moves = "UD";
    bool expected_answer = true;
    assert(solution.judgeCircle(given_moves) == expected_answer);

    given_moves = "LLLLDDRR";
    expected_answer = false;
    assert(solution.judgeCircle(given_moves) == expected_answer);

    return 0;
}

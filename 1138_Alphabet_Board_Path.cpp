//#1138 Alphabet Board Path - https://leetcode.com/problems/alphabet-board-path/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        string result;
        pair<int, int> pos = {0, 0};
        for(int i = 0; i < (int)target.size(); i++)
        {
            pair<int, int> pos_letter = {((int)target[i] - (int)'a') / 5, ((int)target[i] - (int)'a') % 5};
            result += string(max(0, pos.first - pos_letter.first), 'U');
            result += string(max(0, pos.second - pos_letter.second), 'L');
            result += string(max(0, pos_letter.first - pos.first), 'D');
            result += string(max(0, pos_letter.second - pos.second), 'R');
            pos = pos_letter;
            result += '!';
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_target = "zb";
    string expected_answer = "DDDDD!UUUUUR!";
    assert(solution.alphabetBoardPath(given_target) == expected_answer);

    given_target = "code";
    expected_answer = "RR!DDRR!UUL!R!";
    assert(solution.alphabetBoardPath(given_target) == expected_answer);

    return 0;
}

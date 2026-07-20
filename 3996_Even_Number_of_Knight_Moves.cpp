//#3996 Even Number of Knight Moves - https://leetcode.com/problems/even-number-of-knight-moves/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return ((start[0] + start[1]) & 1) == ((target[0] + target[1]) & 1);
    }
};

int main()
{
    Solution solution;
    vector<int> givenStart = {1, 1};
    vector<int> givenEnd = {2, 2};
    bool expectedAnswer = true;
    assert(solution.canReach(givenStart, givenEnd) == expectedAnswer);

    givenStart = {4, 5};
    givenEnd = {6, 6};
    expectedAnswer = false;
    assert(solution.canReach(givenStart, givenEnd) == expectedAnswer);

    return 0;
}

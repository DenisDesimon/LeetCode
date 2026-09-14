//#836 Rectangle Overlap - https://leetcode.com/problems/rectangle-overlap/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       return min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
               min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
    }
};

int main()
{
    Solution solution;
    vector<int> givenRec1 = {0, 0, 2, 2};
    vector<int> givenRec2 = {1, 1, 3, 3};
    bool expectedAnswer = true;
    assert(solution.isRectangleOverlap(givenRec1, givenRec2) == expectedAnswer);

    givenRec1 = {0, 0, 1, 1};
    givenRec2 = {1, 0, 2, 1};
    expectedAnswer = false;
    assert(solution.isRectangleOverlap(givenRec1, givenRec2) == expectedAnswer);


    return 0;
}

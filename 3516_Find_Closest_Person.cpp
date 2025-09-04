//#3516 Find Closest Person - https://leetcode.com/problems/find-closest-person/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x - z) == abs(y - z))
            return 0;
        return abs(x - z) > abs(y - z) ? 2 : 1;
    }
};

int main()
{
    Solution solution;
    int givenX = 2;
    int givenY = 7;
    int givenZ = 4;
    int expectedAnswer = 1;
    assert(solution.findClosest(givenX, givenY, givenZ) == expectedAnswer);

    givenX = 2;
    givenY = 5;
    givenZ = 6;
    expectedAnswer = 2;
    assert(solution.findClosest(givenX, givenY, givenZ) == expectedAnswer);

    return 0;
}

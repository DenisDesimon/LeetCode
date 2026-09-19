//#1401 Circle and Rectangle Overlapping - https://leetcode.com/problems/circle-and-rectangle-overlapping/
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist = 0;
        if(xCenter < x1 || xCenter > x2)
            dist += min(pow(xCenter - x1, 2), pow(xCenter - x2, 2));
        if(yCenter < y1 || yCenter > y2)
            dist += min(pow(yCenter - y1, 2), pow(yCenter - y2, 2));
        return dist <= radius * radius;
    }
};

int main()
{
    Solution solution;
    int givenRaduis = 1;
    int givenXcenter = 0;
    int givenYcenter = 0;
    int givenX1 = 1;
    int givenY1 = -1;
    int givenX2 = 3;
    int givenY2 = 1;
    bool expectedAnswer = true;
    assert(solution.checkOverlap(givenRaduis, givenXcenter, givenYcenter, givenX1, givenY1, givenX2, givenY2) == expectedAnswer);

    givenRaduis = 1;
    givenXcenter = 1;
    givenYcenter = 1;
    givenX1 = 1;
    givenY1 = -3;
    givenX2 = 2;
    givenY2 = -1;
    expectedAnswer = false;
    assert(solution.checkOverlap(givenRaduis, givenXcenter, givenYcenter, givenX1, givenY1, givenX2, givenY2) == expectedAnswer);


    return 0;
}

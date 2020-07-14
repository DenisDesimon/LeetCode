//#1344 Angle Between Hands of a Clock - https://leetcode.com/problems/angle-between-hands-of-a-clock/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_hour = (hour % 12) * 30 + minutes * 0.5;
        double angle_minute = minutes * 6;
        double result = abs(angle_hour - angle_minute);
        return min(result, 360 - result);
    }
};

int main()
{
    Solution solution;
    int given_hour = 3;
    int given_minutes = 15;
    double expected_answer = 7.50000;
    assert(solution.angleClock(given_hour, given_minutes) == expected_answer);

    given_hour = 12;
    given_minutes = 30;
    expected_answer = 165;
    assert(solution.angleClock(given_hour, given_minutes) == expected_answer);

    return 0;
}

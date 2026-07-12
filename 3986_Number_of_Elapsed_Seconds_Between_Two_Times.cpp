//#3986 Number of Elapsed Seconds Between Two Times - https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int result = 0;
        result  += (endTime[0] - '0' - (startTime[0] - '0')) * 10 * 3600;
        result += (endTime[1] - '0' - (startTime[1] - '0')) * 3600;
        result += (endTime[3] - '0' - (startTime[3] - '0')) * 10 * 60;
        result += (endTime[4] - '0' - (startTime[4] - '0')) * 60;
        result += (endTime[6] - '0' - (startTime[6] - '0')) * 10;
        result += (endTime[7] - '0' - (startTime[7] - '0'));
        return result;
    }
};

int main()
{
    Solution solution;
    string givenStart = "01:00:00";
    string givenEnd = "01:00:25";
    int expectedAnswer = 25;
    assert(solution.secondsBetweenTimes(givenStart, givenEnd) == expectedAnswer);

    givenStart = "12:34:56";
    givenEnd = "13:00:00";
    expectedAnswer = 1504;
    assert(solution.secondsBetweenTimes(givenStart, givenEnd) == expectedAnswer);

    return 0;
}

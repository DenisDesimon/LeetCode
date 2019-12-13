//#539 Minimum Time Difference - https://leetcode.com/problems/minimum-time-difference/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int result = INT_MAX;
        int first, second;
        first = ((timePoints[0][0] - '0') * 10 + (timePoints[0][1] - '0')) * 60  +
                        ((timePoints[0][3] - '0') * 10 + (timePoints[0][4] - '0'));
        for(int i = 1; i < (int)timePoints.size(); i++)
        {
            second = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60  +
                            ((timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0'));
            result = min({result, abs(first - second), 1440 - abs(first - second)});
            first = second;
        }
        first = ((timePoints[0][0] - '0') * 10 + (timePoints[0][1] - '0')) * 60  +
                        ((timePoints[0][3] - '0') * 10 + (timePoints[0][4] - '0'));
        result = min({result, abs(first - second), 1440 - abs(first - second)});
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_time = {"05:31", "22:08", "00:35"};
    int expected_answer = 147;
    assert(solution.findMinDifference(given_time) == expected_answer);

    given_time = {"23:59", "00:00"};
    expected_answer = 1;
    assert(solution.findMinDifference(given_time) == expected_answer);

    return 0;
}

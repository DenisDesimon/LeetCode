//#3439 Reschedule Meetings for Maximum Free Time I - https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int result = 0;
        int left = 0, right = 0, freeTime = 0, n = startTime.size();
        while(right <= n)
        {
            freeTime += (right == n ? eventTime:  startTime[right]) - (right != 0 ? endTime[right - 1] : 0);
            result = max(result, freeTime);
            right++;
            if(right > k)
            {
                freeTime -= startTime[left] - (left != 0 ? endTime[left - 1] : 0);
                left++;
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> givenStartTime = {1, 3};
    vector<int> givenEndTime = {2, 5};
    int givenEventTime = 5;
    int givenK = 1;
    int expectedAnswer = 2;
    assert(solution.maxFreeTime(givenEventTime, givenK, givenStartTime, givenEndTime) == expectedAnswer);

    givenStartTime = {0, 2, 9};
    givenEndTime = {1, 4, 10};
    givenEventTime = 10;
    givenK = 1;
    expectedAnswer = 6;
    assert(solution.maxFreeTime(givenEventTime, givenK, givenStartTime, givenEndTime) == expectedAnswer);

    return 0;
}

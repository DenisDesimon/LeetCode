//#3635 Earliest Finish Time for Land and Water Rides II - https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
private:
    int minTime(vector<int>& firstStartTime, vector<int>& firstDuration, vector<int>& secondStartTime, vector<int>& secondDuration){
        int timeFirst = INT_MAX;
        for(int i = 0; i < (int)firstStartTime.size(); i++)
        {
            timeFirst = min(timeFirst, firstStartTime[i] + firstDuration[i]);
        }
        int result = INT_MAX;
        for(int i = 0; i < (int)secondStartTime.size(); i++)
        {
            result = min(result, max(timeFirst, secondStartTime[i]) + secondDuration[i]);
        }
        return result;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(minTime(landStartTime, landDuration, waterStartTime, waterDuration),
                   minTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};

int main()
{
    Solution solution;
    vector<int> givenLandStartTime  = {2, 8};
    vector<int> givenLandDuration  = {4, 1};
    vector<int> givenWaterStartTime  = {6};
    vector<int> givenWaterDuration  = {3};
    int expectedAnswer = 9;
    assert(solution.earliestFinishTime(givenLandStartTime, givenLandDuration, givenWaterStartTime, givenWaterDuration) == expectedAnswer);

    givenLandStartTime  = {5};
    givenLandDuration  = {3};
    givenWaterStartTime  = {1};
    givenWaterDuration  = {10};
    expectedAnswer = 14;
    assert(solution.earliestFinishTime(givenLandStartTime, givenLandDuration, givenWaterStartTime, givenWaterDuration) == expectedAnswer);

    return 0;
}

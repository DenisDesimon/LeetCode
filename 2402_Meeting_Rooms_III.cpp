//2402 Meeting Rooms III - https://leetcode.com/problems/meeting-rooms-iii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        sort(meetings.begin(), meetings.end());
        vector<int> meetCounts(n);
        for(int i = 0; i < n; i++)
            freeRooms.push(i);
        for(int i = 0; i < (int)meetings.size(); i++)
        {
            int start = meetings[i][0], end = meetings[i][1];
            while(!busyRooms.empty() && busyRooms.top().first <= start)
            {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if(!freeRooms.empty())
            {
                busyRooms.push({end, freeRooms.top()});
                meetCounts[freeRooms.top()]++;
                freeRooms.pop();
            }
            else
            {
                meetCounts[busyRooms.top().second]++;
                busyRooms.push({busyRooms.top().first + end - start, busyRooms.top().second});
                busyRooms.pop();
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(meetCounts[result] < meetCounts[i])
                result = i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMeetings  = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    int givenN = 2;
    int expectedAnswer = 0;
    assert(solution.mostBooked(givenN, givenMeetings) == expectedAnswer);

    givenMeetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    givenN = 3;
    expectedAnswer = 1;
    assert(solution.mostBooked(givenN, givenMeetings) == expectedAnswer);

    return 0;
}

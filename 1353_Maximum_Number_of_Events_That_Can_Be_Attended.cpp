//#1353 Maximum Number of Events That Can Be Attended - https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int endDay = 0;
        int result = 0;
        for(auto &event : events)
            endDay = max(endDay, event[1]);
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> lowEndDay;
        for(int start = 1, event = 0; start <= endDay; start++){
            while(event < (int)events.size() && start >= events[event][0])
                lowEndDay.push(events[event++][1]);
            while(!lowEndDay.empty() && lowEndDay.top() < start)
                lowEndDay.pop();
            if(!lowEndDay.empty())
            {
                result++;
                lowEndDay.pop();
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_events = {{1,2}, {2, 3}, {3, 4}};
    int expected_answer = 3;
    assert(solution.maxEvents(given_events) == expected_answer);

    given_events = {{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}};
    expected_answer = 5;
    assert(solution.maxEvents(given_events) == expected_answer);

    return 0;
}

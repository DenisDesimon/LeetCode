//#2054 Two Best Non-Overlapping Events - https://leetcode.com/problems/two-best-non-overlapping-events/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> timeEnd;
        sort(events.begin(), events.end());
        int result = 0, maxIntersected = 0;
        for(auto event : events)
        {
            while(!timeEnd.empty() && event[0] > timeEnd.top().first)
            {
                maxIntersected = max(maxIntersected, timeEnd.top().second);
                timeEnd.pop();
            }
            result = max(result, maxIntersected + event[2]);
            timeEnd.push({event[1], event[2]});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    int expected_answer = 4;
    assert(solution.maxTwoEvents(given_events) == expected_answer);

    given_events = {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};
    expected_answer = 8;
    assert(solution.maxTwoEvents(given_events) == expected_answer);

    return 0;
}

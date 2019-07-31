//#57 Insert Interval - https://leetcode.com/problems/insert-interval/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};
        newInterval = {newInterval[1], newInterval[0]};
        auto left_iter = lower_bound(intervals.begin(), intervals.end(), newInterval, [](vector<int> a, vector<int> b){return a[1] < b[1];});
        if(left_iter != intervals.end() && newInterval[0] >= (*left_iter)[0])
            {
                (*left_iter)[0] = min((*left_iter)[0], newInterval[1]);
                (*left_iter)[1] = max((*left_iter)[1], newInterval[0]);
            }
        else
            {
                left_iter = intervals.insert(left_iter, {{newInterval[1], newInterval[0]}});
            }
        swap(newInterval[0], newInterval[1]);
        auto right_iter = lower_bound(left_iter + 1, intervals.end(), newInterval, [](vector<int> a, vector<int> b){return a[1] < b[1];});
        if(right_iter != intervals.end() && newInterval[1] >= (*right_iter)[0])
            {
                (*left_iter)[1] = (*right_iter)[1];
                intervals.erase(right_iter);
            }
        if(left_iter < right_iter)
            intervals.erase(left_iter + 1, right_iter);
        return intervals;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_intervals = {{1, 3}, {6, 9}};
    vector<int> given_new_interval = {2, 5};
    vector<vector<int>> expected_answer = {{1, 5}, {6, 9}};
    assert(solution.insert(given_intervals, given_new_interval) == expected_answer);

    given_intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    given_new_interval = {4, 8};
    expected_answer = {{1, 2}, {3, 10}, {12, 16}};
    assert(solution.insert(given_intervals, given_new_interval) == expected_answer);

    return 0;
}

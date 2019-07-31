//#56 Merge Intervals - https://leetcode.com/problems/merge-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        result.push_back(intervals[0]);
        for(int i = 1; i < (int)intervals.size(); i++)
        {
            if(result.back()[1] >= intervals[i][0])
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_intervals = {{1, 4}, {0, 2}, {3, 5}};
    vector<vector<int>> expected_answer = {{0, 5}};
    assert(solution.merge(given_intervals) == expected_answer);

    given_intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    expected_answer = {{1, 6}, {8, 10}, {15, 18}};
    assert(solution.merge(given_intervals) == expected_answer);

    return 0;
}

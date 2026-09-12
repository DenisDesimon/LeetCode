//#3414 Maximum Score of Non-overlapping Intervals - https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> idxs(n);
        for(int i = 0; i < n; i++)
            idxs[i] = i;
        sort(idxs.begin(), idxs.end(), [&](int a, int b){
           return intervals[a][1] < intervals[b][1];
        });
        vector<int> intervalEnd(n);
        for(int i = 0; i < n; i++)
            intervalEnd[i] = intervals[idxs[i]][1];
        vector<pair<long long, vector<int>>> prev(n + 1, {0, {}});
        for(int k = 0; k < 4; k++)
        {
            vector<pair<long long, vector<int>>> cur(n + 1);
            for(int i = 1; i <= n; i++)
            {
                int idx = idxs[i - 1];
                int left = intervals[idx][0];
                int w = intervals[idx][2];
                int right = lower_bound(intervalEnd.begin(), intervalEnd.end(), left) - intervalEnd.begin();
                pair<long long, vector<int>> take = prev[right];
                take.first -= w;
                take.second.insert(upper_bound(take.second.begin(), take.second.end(), idx), idx);
                cur[i] = min(cur[i - 1], take);
            }
            prev = move(cur);
        }
        return prev.back().second;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenIntervals = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}, {6, 9, 3}, {6, 7, 1}, {8, 9, 1}};
    vector<int> expectedAnswer = {2, 3};
    assert(solution.maximumWeight(givenIntervals) == expectedAnswer);

    givenIntervals = {{5, 8, 1}, {6, 7, 7}, {4, 7, 3}, {9, 10, 6}, {7, 8, 2}, {11, 14, 3} ,{3 ,5, 5}};
    expectedAnswer = {1, 3, 5, 6};
    assert(solution.maximumWeight(givenIntervals) == expectedAnswer);


    return 0;
}

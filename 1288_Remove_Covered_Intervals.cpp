//#1288 Remove Covered Intervals - https://leetcode.com/problems/remove-covered-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int result = intervals.size();
        sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){
            if(a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        });
        for(int i = 1; i < (int)intervals.size(); i++)
        {
            if(intervals[i - 1][1] >= intervals[i][1])
            {
                result--;
                intervals[i] = intervals[i - 1];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_intervals = {{1, 4}, {3, 6}, {2, 8}};
    int expected_answer = 2;
    assert(solution.removeCoveredIntervals(given_intervals) == expected_answer);

    given_intervals = {{1, 4}, {1, 6}, {1, 3}};
    expected_answer = 1;
    assert(solution.removeCoveredIntervals(given_intervals) == expected_answer);

    return 0;
}

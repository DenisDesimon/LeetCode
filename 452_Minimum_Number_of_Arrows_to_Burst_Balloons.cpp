//#452 Minimum Number of Arrows to Burst Balloons - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});
        int last_end = points[0][1];
        int result = 1;
        for(int i = 1; i < (int)points.size(); i++)
        {
            if(points[i][0] <= last_end)
                continue;
            result++;
            last_end = points[i][1];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{10, 16}, {2, 6}, {1, 6}, {7, 12}};
    int expected_answer = 2;
    assert(solution.findMinArrowShots(given_points) == expected_answer);

    given_points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    expected_answer = 2;
    assert(solution.findMinArrowShots(given_points) == expected_answer);

    return 0;
}

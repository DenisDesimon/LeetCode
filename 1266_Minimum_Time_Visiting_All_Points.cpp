//#1266 Minimum Time Visiting All Points - https://leetcode.com/problems/minimum-time-visiting-all-points/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        int result = 0;
        for(int i = 1; i < (int)points.size(); i++)
        {
            result += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{1, 1}, {3, 4}, {-1, 0}};
    int expected_answer = 7;
    assert(solution.minTimeToVisitAllPoints(given_points) == expected_answer);

    given_points = {{3, 2}, {-2, 2}};
    expected_answer = 5;
    assert(solution.minTimeToVisitAllPoints(given_points) == expected_answer);

    return 0;
}

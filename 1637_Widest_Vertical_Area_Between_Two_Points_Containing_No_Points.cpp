//#1637 Widest Vertical Area Between Two Points Containing No Points - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int result = 0;
        sort(points.begin(), points.end(), [](vector<int> &left, vector<int> &right){return left[0] < right[0];});
        for(int i = 0; i < (int)points.size() - 1; i++)
            result = max(result, points[i + 1][0] - points[i][0]);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    int expected_answer = 1;
    assert(solution.maxWidthOfVerticalArea(given_points) == expected_answer);

    given_points = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    expected_answer = 3;
    assert(solution.maxWidthOfVerticalArea(given_points) == expected_answer);

    return 0;
}

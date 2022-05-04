//#2250 Count Number of Rectangles Containing Each Point - https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> result;
        vector<vector<int>> height(101);
        for(auto &rectangle : rectangles)
            height[rectangle[1]].push_back(rectangle[0]);
        for(auto &h : height)
            sort(h.begin(), h.end());
        for(auto &point : points)
        {
            result.push_back(0);
            for(int i = point[1]; i < 101; i++)
            {
                auto lower = lower_bound(height[i].begin(), height[i].end(), point[0]);
                result.back() += height[i].end() - lower;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_rectangles = {{1, 2}, {2, 3}, {2, 5}};
    vector<vector<int>> given_points = {{2, 1}, {1, 4}};
    vector<int> expected_answer = {2, 1};

    assert(solution.countRectangles(given_rectangles, given_points) == expected_answer);

    given_rectangles = {{1, 1}, {2, 2}, {3, 3}};
    given_points = {{1, 3}, {1, 1}};
    expected_answer = {1, 3};

    assert(solution.countRectangles(given_rectangles, given_points) == expected_answer);

    return 0;
}

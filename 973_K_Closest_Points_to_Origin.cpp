//#973 K Closest Points to Origin - https://leetcode.com/problems/k-closest-points-to-origin/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(),
                    [](vector<int> a, vector<int> b){return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];});
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{5, -1}, {3, 3}, {-2, 4}};
    vector<vector<int>> expected_answer = {{3, 3}, {-2, 4}};
    int given_K = 2;
    assert(solution.kClosest(given_points, given_K) == expected_answer);

    given_points = {{1, 3}, {-2, 2}};
    expected_answer = {{-2, 2}};
    given_K = 1;
    assert(solution.kClosest(given_points, given_K) == expected_answer);

    return 0;
}

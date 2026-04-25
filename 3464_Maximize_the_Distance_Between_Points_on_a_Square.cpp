//#3464 Maximize the Distance Between Points on a Square - https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> sortedPoints;
        for(auto &point : points)
        {
            if(point[0] == 0)
                sortedPoints.push_back(point[1]);
            else if(point[1] == side)
                sortedPoints.push_back(point[0] + side);
            else if(point[0] == side)
                sortedPoints.push_back(3LL * side - point[1]);
            else
                sortedPoints.push_back(4LL * side - point[0]);
        }
        sort(sortedPoints.begin(), sortedPoints.end());
        auto check = [&](long long dist) -> bool{
            for(auto &point : sortedPoints)
            {
                long long cur = point;
                long long end = 4LL * side + point - dist;
                int i = 0;
                for(; i < k - 1; i++)
                {
                    auto nextPoint = lower_bound(sortedPoints.begin(), sortedPoints.end(), cur + dist);
                    if(nextPoint == sortedPoints.end() || *nextPoint > end)
                        break;
                    cur = *nextPoint;
                }
                if(i == k - 1)
                    return true;
            }
            return false;
        };
        int result = 0;
        long long left = 1, right = side;
        while(left <= right)
        {
            long long mid = (right - left) / 2 + left;
            if(check(mid))
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenSide = 2;
    vector<vector<int>> givenPoints = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
    int givenK = 4;
    int expectedAnswer = 2;
    assert(solution.maxDistance(givenSide, givenPoints, givenK) == expectedAnswer);

    givenSide = 2;
    givenPoints = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    givenK = 4;
    expectedAnswer = 1;
    assert(solution.maxDistance(givenSide, givenPoints, givenK) == expectedAnswer);

    return 0;
}

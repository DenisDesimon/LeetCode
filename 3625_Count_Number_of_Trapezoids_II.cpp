//#3625 Count Number of Trapezoids II - https://leetcode.com/problems/count-number-of-trapezoids-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercepts;
        unordered_map<int, vector<float>> midPointToSlope;
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                float k, intercept;
                if(x2 == x1)
                {
                    k = inf;
                    intercept = x1;
                }
                else
                {
                    k = (float)dy / dx;
                    intercept = (float)(y1 * dx - x1 * dy) / dx;
                }
                int midPoint = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercepts[k].push_back(intercept);
                midPointToSlope[midPoint].push_back(k);
            }
        }
        for(auto &[_, intercepts] : slopeToIntercepts)
        {
            if(intercepts.size() == 1)
                continue;
            unordered_map<float, int> countIntercepts;
            for(auto &intercept : intercepts)
                countIntercepts[intercept]++;
            int sum = 0;
            for(auto &[_, count] : countIntercepts)
            {
                result += sum * count;
                sum += count;
            }
        }
        for(auto &[_, slopes] : midPointToSlope)
        {
            if(slopes.size() == 1)
                continue;
            unordered_map<float, int> countSlopes;
            for(auto &slope : slopes)
                countSlopes[slope]++;
            int sum = 0;
            for(auto &[_, count] : countSlopes)
            {
                result -= sum * count;
                sum += count;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenPoints = {{-3, 2} ,{3, 0}, {2, 3} ,{3, 2}, {2, -3}};
    int expectedAnswer = 2;
    assert(solution.countTrapezoids(givenPoints) == expectedAnswer);

    givenPoints = {{0, 0}, {1, 0}, {0, 1}, {2, 1}};
    expectedAnswer = 1;
    assert(solution.countTrapezoids(givenPoints) == expectedAnswer);

    return 0;
}

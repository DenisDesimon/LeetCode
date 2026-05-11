//#3923 Minimum Generations to Target Point - https://leetcode.com/problems/minimum-generations-to-target-point/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        unordered_set<int> uniquePoints;
        int targetH = target[0] + target[1] * 7 + target[2] * 49;
        for(auto &point : points)
        {
            int curH = point[0] + point[1] * 7 + point[2] * 49;
            if(curH == targetH)
                return 0;
            uniquePoints.insert(curH);
        }
        int gen = 1;
        while(true)
        {
            int n = points.size();
            bool flag = false;
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    vector<int> newPoint = {(points[i][0] + points[j][0]) / 2, (points[i][1] + points[j][1]) / 2,
                                                    (points[i][2] + points[j][2]) / 2};
                    int newH = newPoint[0] + newPoint[1] * 7 + newPoint[2] * 49;
                    if(uniquePoints.count(newH))
                        continue;
                    if(newH == targetH)
                        return gen;
                    flag = true;
                    points.push_back(newPoint);
                    uniquePoints.insert(newH);
                }
            }
            if(!flag)
                break;
            gen++;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenPoints  = {{0, 0, 0}, {6, 6, 6}};
    vector<int> givenTarget = {3, 3, 3};
    int expectedAnswer = 1;
    assert(solution.minGenerations(givenPoints, givenTarget) == expectedAnswer);

    givenPoints = {{0, 0, 0}, {5, 5, 5}};
    givenTarget = {1, 1, 1};
    expectedAnswer = 2;
    assert(solution.minGenerations(givenPoints, givenTarget) == expectedAnswer);

    return 0;
}

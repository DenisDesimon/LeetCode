//#812 Largest Triangle Area - https://leetcode.com/problems/largest-triangle-area/
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
private:
    double getSideLength(vector<int> &left, vector<int> &right){
        return sqrt((left[0] - right[0]) * (left[0] - right[0]) + (left[1] - right[1]) * (left[1] - right[1]));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        for(int i = 0; i < (int)points.size(); i++)
        {
            for(int j = i + 1; j < (int)points.size(); j++)
            {
                for(int k = j + 1; k < (int)points.size(); k++)
                {
                    double a = getSideLength(points[i], points[j]);
                    double b = getSideLength(points[j], points[k]);
                    double c = getSideLength(points[i], points[k]);
                    double halfP = (a + b + c) / 2;
                    result = max(result, sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c)));
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenNums = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    double expectedAnswer = 2;
    assert((solution.largestTriangleArea(givenNums) - expectedAnswer) < 0.000001);

    givenNums = {{1, 0}, {0 ,0}, {0, 1}};
    expectedAnswer = 0.5;
    assert((solution.largestTriangleArea(givenNums) - expectedAnswer) < 0.000001);

    return 0;
}

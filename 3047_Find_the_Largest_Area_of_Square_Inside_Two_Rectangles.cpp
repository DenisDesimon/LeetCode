//#3047 Find the Largest Area of Square Inside Two Rectangles - https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxLen = 0;
        for(int i = 0; i < (int)bottomLeft.size(); i++)
        {
            for(int j = i + 1; j < (int)bottomLeft.size(); j++)
            {
                int width = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int height = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                long long len = min(width, height);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen * maxLen;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenBottomLeft  = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> givenBottomRight  = {{3, 3}, {4, 4}, {6, 6}};
    long long expectedAnswer = 1;
    assert(solution.largestSquareArea(givenBottomLeft, givenBottomRight) == expectedAnswer);

    givenBottomLeft  = {{1, 1}, {1, 3}, {1, 5}};
    givenBottomRight  = {{5, 5}, {5, 7}, {5, 9}};
    expectedAnswer = 4;
    assert(solution.largestSquareArea(givenBottomLeft, givenBottomRight) == expectedAnswer);

    return 0;
}

//#3027 Find the Number of Ways to Place People II - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;
        sort(points.begin(), points.end(),
             [](vector<int> &left, vector<int> &right){if(left[0] == right[0]) return left[1] > right[1];return left[0] < right[0];});
        for(int i = 0; i < (int)points.size(); i++)
        {
            int topLeft = points[i][1];
            int maxBottom = INT_MIN;
            for(int j = i + 1; j < (int)points.size(); j++)
            {
                if(topLeft >= points[j][1] && maxBottom < points[j][1])
                {
                    result++;
                    maxBottom = points[j][1];
                    if(maxBottom == topLeft)
                        break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenPoints = {{6,2}, {4, 4}, {2, 6}};
    int expectedAnswer = 2;
    assert(solution.numberOfPairs(givenPoints) == expectedAnswer);

    givenPoints = {{3,1}, {1, 3}, {1, 1}};
    expectedAnswer = 2;
    assert(solution.numberOfPairs(givenPoints) == expectedAnswer);

    return 0;
}

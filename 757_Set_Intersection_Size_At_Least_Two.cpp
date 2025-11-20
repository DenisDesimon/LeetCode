//#757 Set Intersection Size At Least Two - https://leetcode.com/problems/set-intersection-size-at-least-two/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &left, vector<int> &right) {if(left[1] == right[1]) return left[0] < right[0];
                                                            return left[1] < right[1];});
        int result = 2;
        int left = intervals[0][1] - 1, right = intervals[0][1];
        for(auto &interval : intervals)
        {
            if(right < interval[0])
            {
                result += 2;
                left = interval[1] - 1;
                right = interval[1];
            }
            else if(left < interval[0])
            {
                result++;
                if(right != interval[1])
                {
                    left = right;
                    right = interval[1];
                }
                else
                    left = right - 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenIntervals = {{1, 3}, {3, 7}, {5, 7}, {7, 8}};
    int expectedAnswer = 5;
    assert(solution.intersectionSizeTwo(givenIntervals) == expectedAnswer);

    givenIntervals = {{2, 10}, {3, 7}, {3, 15}, {4, 11}, {6, 12}, {6, 16}, {7, 8}, {7, 11}, {7, 15}, {11, 12}};
    expectedAnswer = 5;
    assert(solution.intersectionSizeTwo(givenIntervals) == expectedAnswer);

    return 0;
}

//#1848 Minimum Distance to the Target Element - https://leetcode.com/problems/minimum-distance-to-the-target-element/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for(int i = 0; start + i < n || start - i >= 0 ; i++)
        {
            if(start - i >= 0 && nums[start - i] == target)
                return i;
            if(start + i < n && nums[start + i] == target)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4, 5};
    int givenTarget = 5;
    int givenStart = 3;
    int expected_answer = 1;
    assert(solution.getMinDistance(givenNums, givenTarget, givenStart) == expected_answer);

    givenNums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    givenTarget = 1;
    givenStart = 0;
    expected_answer = 0;
    assert(solution.getMinDistance(givenNums, givenTarget, givenStart) == expected_answer);

    return 0;
}

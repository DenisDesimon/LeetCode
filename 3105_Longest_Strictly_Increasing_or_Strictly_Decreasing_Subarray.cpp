//#3105 Longest Strictly Increasing or Strictly Decreasing Subarray - https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1;
        int countIncreasing = 1, countDecreasing = 1;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                countDecreasing = 1;
                countIncreasing++;
                result = max(result, countIncreasing);
            }
            else if(nums[i] < nums[i - 1])
            {
                countIncreasing = 1;
                countDecreasing++;
                result = max(result, countDecreasing);
            }
            else
            {
                countIncreasing = 1;
                countDecreasing = 1;
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> givenNums = {1, 4, 3, 3, 2};
    int expectedAnswer = 2;
    assert(solution.longestMonotonicSubarray(givenNums) == expectedAnswer);

    givenNums = {3, 2, 1};
    expectedAnswer = 3;
    assert(solution.longestMonotonicSubarray(givenNums) == expectedAnswer);

    return 0;
}

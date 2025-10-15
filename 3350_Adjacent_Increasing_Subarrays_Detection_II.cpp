//#3350 Adjacent Increasing Subarrays Detection II - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int result = 0, left = 0, right = 1;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
                right++;
            else
            {
                left = right;
                right = 1;
            }
            result = max({result, min(left, right), right / 2});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int expectedAnswer = 3;
    assert(solution.maxIncreasingSubarrays(givenNums) == expectedAnswer);

    givenNums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    expectedAnswer = 2;
    assert(solution.maxIncreasingSubarrays(givenNums) == expectedAnswer);

    return 0;
}

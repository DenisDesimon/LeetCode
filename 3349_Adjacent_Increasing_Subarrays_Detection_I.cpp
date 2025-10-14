//#3349 Adjacent Increasing Subarrays Detection I - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 1;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
                right++;
            else
            {
                left = right;
                right = 1;
            }
            if(right == k * 2 || (min(left, right) >= k))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 5, 7 ,8, 9 ,2, 3, 4, 3, 1};
    int givenK = 3;
    bool expectedAnswer = true;
    assert(solution.hasIncreasingSubarrays(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    givenK = 5;
    expectedAnswer = false;
    assert(solution.hasIncreasingSubarrays(givenNums, givenK) == expectedAnswer);

    return 0;
}

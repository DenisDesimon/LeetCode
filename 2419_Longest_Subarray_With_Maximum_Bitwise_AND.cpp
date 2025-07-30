//#2419 Longest Subarray With Maximum Bitwise AND - https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0;
        int result = 0;
        int subArrayLength = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] > maxNum)
            {
                result = 1;
                subArrayLength = 1;
                maxNum = nums[i];
            }
            else if(nums[i] == maxNum)
            {
                subArrayLength++;
                result = max(result, subArrayLength);
            }
            else
            {
                subArrayLength = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 3, 2, 2};
    int expectedAnswer = 2;
    assert(solution.longestSubarray(givenNums) == expectedAnswer);

    givenNums = {1, 2, 3, 4};
    expectedAnswer = 1;
    assert(solution.longestSubarray(givenNums) == expectedAnswer);

    return 0;
}

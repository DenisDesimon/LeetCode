//#2411 Smallest Subarrays With Maximum Bitwise OR - https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> closestPos(32, -1);
        for(int left = (int)nums.size() - 1; left >= 0; left--)
        {
            int right = left;
            for(int i = 0; i < 32; i++)
            {
                if(nums[left] & (1 << i))
                    closestPos[i] = left;
                else if(closestPos[i] != -1)
                    right = max(right, closestPos[i]);
            }
            result[left] = right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 0, 2, 1, 3};
    vector<int> expectedAnswer = {3, 3, 2, 2, 1};
    assert(solution.smallestSubarrays(givenNums) == expectedAnswer);

    givenNums = {1, 2};
    expectedAnswer = {2, 1};
    assert(solution.smallestSubarrays(givenNums) == expectedAnswer);

    return 0;
}

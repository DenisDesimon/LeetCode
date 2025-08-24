//#1493 Longest Subarray of 1's After Deleting One Element - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, cur = 0, result = 0;
        for(auto num : nums)
        {
            if(!num)
            {
                result = max(prev + cur, result);
                prev = cur;
                cur = 0;
            }
            else
                cur++;
        }
        result = max(prev + cur, result);
        return cur == (int)nums.size() ? cur - 1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 0, 1};
    int expectedAnswer = 3;
    assert(solution.longestSubarray(givenNums) == expectedAnswer);

    givenNums = {0, 1, 1, 1, 0 ,1, 1, 0, 1};
    expectedAnswer = 5;
    assert(solution.longestSubarray(givenNums) == expectedAnswer);

    return 0;
}

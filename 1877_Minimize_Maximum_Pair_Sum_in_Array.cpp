//#1877 Minimize Maximum Pair Sum in Array - https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = INT_MIN;
        for(int i = 0; i < (int)nums.size() / 2; i++)
        {
            result = max(result, nums[i] + nums[nums.size() - i - 1]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {3, 5, 2, 3};
    int expectedAnswer = 7;
    assert(solution.minPairSum(givenNums) == expectedAnswer);

    givenNums = {3, 5, 4, 2, 4, 6};
    expectedAnswer = 8;
    assert(solution.minPairSum(givenNums) == expectedAnswer);

    return 0;
}

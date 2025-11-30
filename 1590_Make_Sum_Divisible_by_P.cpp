//#1590 Make Sum Divisible by P - https://leetcode.com/problems/make-sum-divisible-by-p/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int result = nums.size();
        int sum = 0;
        for(auto &num : nums)
            sum = (sum + num) % p;
        int target = sum % p;
        if(!target)
            return 0;
        sum = 0;
        unordered_map<int, int> prefixSumIdx;
        prefixSumIdx[0] = -1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            sum = (sum + nums[i]) % p;
            int subSum = (sum - target + p) % p;
            if(prefixSumIdx.count(subSum))
                result = min(result, i - prefixSumIdx[subSum]);
            prefixSumIdx[sum] = i;
        }
        return result == (int)nums.size() ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
    int givenP = 26;
    int expectedAnswer = 3;
    assert(solution.minSubarray(givenNums, givenP) == expectedAnswer);

    givenNums = {1, 2, 3};
    givenP = 7;
    expectedAnswer = -1;
    assert(solution.minSubarray(givenNums, givenP) == expectedAnswer);

    return 0;
}

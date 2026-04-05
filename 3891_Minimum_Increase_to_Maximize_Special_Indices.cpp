//#3891 Minimum Increase to Maximize Special Indices - https://leetcode.com/problems/minimum-increase-to-maximize-special-indices/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    long long solve(vector<int>& nums, int cur, bool isSkipUsed, vector<vector<long long>> &dp){
        if(cur >= (int)nums.size() - 1)
            return 0;
        if(dp[cur][isSkipUsed] != -1)
            return dp[cur][isSkipUsed];
        long long take = 0;
        long long skip = LLONG_MAX;
        take = max(0, max(nums[cur - 1], nums[cur + 1]) - nums[cur] + 1) + solve(nums, cur + 2, isSkipUsed, dp);
        if(!isSkipUsed)
        {
            skip = solve(nums, cur + 1, 1, dp);
        }
        return dp[cur][isSkipUsed] = min(take, skip);
    }
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if(n % 2)
        {
            long long result = 0;
            for(int i = 1; i < n - 1; i += 2)
            {
                result += max(0, max(nums[i - 1], nums[i + 1]) - nums[i] + 1);
            }
            return result;
        }
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(nums, 1, 0, dp);
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 2};
    long long expectedAnswer = 1;
    assert(solution.minIncrease(givenNums) == expectedAnswer);

    givenNums = {5, 2, 1, 4, 3};
    expectedAnswer = 4;
    assert(solution.minIncrease(givenNums) == expectedAnswer);

    return 0;
}

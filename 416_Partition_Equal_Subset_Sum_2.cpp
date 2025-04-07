//#416 Partition Equal Subset Sum - https://leetcode.com/problems/partition-equal-subset-sum/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp.front() = true;
        for(auto &num : nums)
        {
            if(dp[target])
                return true;
            for(int curTarget = target; curTarget >= num; curTarget--)
            {
                dp[curTarget] = dp[curTarget] || dp[curTarget - num];
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 5};
    bool expected_answer = false;
    assert(solution.canPartition(given_nums) == expected_answer);

    given_nums = {1, 5, 11, 5};
    expected_answer = true;
    assert(solution.canPartition(given_nums) == expected_answer);

    return 0;
}

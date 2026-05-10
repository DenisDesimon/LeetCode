//#2770 Maximum Number of Jumps to Reach the Last Index - https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp.front() = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == -1)
                continue;
            for(int j = i + 1; j < n; j++)
            {
                if(abs(nums[i] - nums[j]) <= target)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 3, 6, 4, 1, 2};
    int givenK = 2;
    int expectedAnswer = 3;
    assert(solution.maximumJumps(givenNums, givenK) == expectedAnswer);

    givenNums = {0, 2, 1, 3};
    givenK = 1;
    expectedAnswer = -1;
    assert(solution.maximumJumps(givenNums, givenK) == expectedAnswer);

    return 0;
}

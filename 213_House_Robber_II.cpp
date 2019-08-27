//#213 House Robber II - https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        int robb_first, robb_last;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        robb_first = dp[n - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        robb_last = dp.back();
        return max(robb_first, robb_last);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 2, 4, 3, 2, 5};
    int expected_answer = 10;
    assert(solution.rob(given_nums) == expected_answer);

    given_nums = {1, 2, 3, 1};
    expected_answer = 4;
    assert(solution.rob(given_nums) == expected_answer);

    return 0;
}

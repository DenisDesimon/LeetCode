//#198 House Robber - https://leetcode.com/problems/house-robber/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 1};
    int expected_answer = 4;
    assert(solution.rob(given_nums) == expected_answer);

    given_nums = {2, 7, 9, 3, 1};
    expected_answer = 12;
    assert(solution.rob(given_nums) == expected_answer);

    return 0;
}

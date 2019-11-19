//#1262 Greatest Sum Divisible by Three - https://leetcode.com/problems/greatest-sum-divisible-by-three/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        for(int i = 1; i <= (int)nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][(3 - nums[i - 1] % 3) % 3] + nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][(4 - nums[i - 1] % 3) % 3] + nums[i - 1]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][(5 - nums[i - 1] % 3) % 3] + nums[i - 1]);
        }
        return dp[nums.size()][0];
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 2, 2, 2};
    int expected_answer = 9;
    assert(solution.maxSumDivThree(given_nums) == expected_answer);

    given_nums = {3, 6, 5, 1, 8};
    expected_answer = 18;
    assert(solution.maxSumDivThree(given_nums) == expected_answer);

    return 0;
}

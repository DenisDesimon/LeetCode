//45 Jump Game II - https://leetcode.com/problems/jump-game-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i - 1] > nums[i])
                continue;
            for(int jump = 1; jump + i < n && jump <= nums[i]; jump++)
                dp[i + jump] = min(dp[i + jump], dp[i] + 1);
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 3, 1, 1, 4};
    int expected_answer = 2;
    assert(solution.jump(given_nums) == expected_answer);

    given_nums = {1, 1, 3, 1, 4};
    expected_answer = 3;
    assert(solution.jump(given_nums) == expected_answer);

    return 0;
}

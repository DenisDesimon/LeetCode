//#486 Predict the Winner - https://leetcode.com/problems/predict-the-winner/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0)
            return true;
        vector<int> dp(nums);
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 5, 2};
    bool expectedAnswer = false;
    assert(solution.predictTheWinner(givenNums) == expectedAnswer);

    givenNums = {1, 5, 233, 7};
    expectedAnswer = true;
    assert(solution.predictTheWinner(givenNums) == expectedAnswer);

    return 0;
}

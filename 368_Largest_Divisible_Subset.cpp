//#368 Largest Divisible Subset - https://leetcode.com/problems/largest-divisible-subset/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), previous(nums.size(), -1);
        vector<int> result;
        int idxMax = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < (int)nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    previous[i] = j;
                }
            }
            if(dp[i] > dp[idxMax])
                idxMax = i;
        }
        int idx = idxMax;
        while(idx >= 0)
        {
            result.push_back(nums[idx]);
            idx = previous[idx];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    vector<int> expected_answer = {2, 1};
    assert(solution.largestDivisibleSubset(given_nums) == expected_answer);

    given_nums = {2, 3, 4, 9, 8};
    expected_answer = {8, 4, 2};
    assert(solution.largestDivisibleSubset(given_nums) == expected_answer);

    return 0;
}

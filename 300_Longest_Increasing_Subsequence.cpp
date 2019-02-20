//#300 Longest Increasing Subsequence - https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int length = 0;
        for(auto num : nums)
        {
            auto index = lower_bound(dp.begin(), dp.begin() + length, num);
            *index = num;
            if(length == (index - dp.begin()))
                length++;
        }
        return length;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int  expected_answer = 4;
    assert(solution.lengthOfLIS(given_nums) == expected_answer);

    given_nums = {23, 26, -1, 0, 1, 3, 101, 5};
    expected_answer = 5;
    assert(solution.lengthOfLIS(given_nums) == expected_answer);

    return 0;
}

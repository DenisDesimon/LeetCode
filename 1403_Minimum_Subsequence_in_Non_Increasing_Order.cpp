//#1403 Minimum Subsequence in Non-Increasing Order - https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> result;
        int sum = accumulate(nums.begin(), nums.end(), 0), cur = 0;
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        for(int i = 0; i < (int)nums.size(); i++)
        {
            cur += nums[i];
            sum -= nums[i];
            result.push_back(nums[i]);
            if(cur > sum)
                break;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 3, 10, 9, 8};
    vector<int> expected_answer = {10, 9};
    assert(solution.minSubsequence(given_nums) == expected_answer);

    given_nums = {4, 4, 7, 6, 7};
    expected_answer = {7, 7, 6};
    assert(solution.minSubsequence(given_nums) == expected_answer);

    return 0;
}

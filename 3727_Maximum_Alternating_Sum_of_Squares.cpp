//#3727 Maximum Alternating Sum of Squares - https://leetcode.com/problems/maximum-alternating-sum-of-squares/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for(auto &num : nums)
            num = num * num;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n / 2; i++)
            result -= nums[i];
        for(int i = n / 2; i < n; i++)
            result += nums[i];
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 3};
    long long expectedAnswer = 12;
    assert(solution.maxAlternatingSum(givenNums) == expectedAnswer);

    givenNums  = {1, -1, 2, -2, 3, -3};
    expectedAnswer = 16;
    assert(solution.maxAlternatingSum(givenNums) == expectedAnswer);

    return 0;
}

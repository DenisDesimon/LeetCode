//#3927 Minimize Array Sum Using Divisible Replacements - https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums.front() == 1)
            return n;
        unordered_map<int, int> fact;
        for(auto &num : nums)
            fact[num] = -1;
        long long result = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = nums[i]; j <= nums.back(); j += nums[i])
            {
                if(fact.count(j) && fact[j] == -1)
                    fact[j] = nums[i];
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            result += fact[nums[i]] == -1 ? nums[i] : fact[nums[i]];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {3, 6, 2};
    long long expectedAnswer = 7;
    assert(solution.minArraySum(givenNums) == expectedAnswer);

    givenNums = {4, 2 ,8, 3};
    expectedAnswer = 9;
    assert(solution.minArraySum(givenNums) == expectedAnswer);

    return 0;
}

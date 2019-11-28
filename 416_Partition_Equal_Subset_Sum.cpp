//#416 Partition Equal Subset Sum - https://leetcode.com/problems/partition-equal-subset-sum/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
    bool has_sum(int target, int length, vector<int>& nums){
        if(target == 0)
            return true;
        if(length == 0 || target < 0)
            return false;
        return has_sum(target - nums[length - 1], length - 1, nums) || has_sum(target, length - 1, nums);

    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;
        int target = sum / 2;
        target -= nums[n - 1];
        return has_sum(target - nums[n - 2], n - 2, nums) ||
                has_sum(target, n - 2, nums);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 5};
    bool expected_answer = false;
    assert(solution.canPartition(given_nums) == expected_answer);

    given_nums = {1, 5, 11, 5};
    expected_answer = true;
    assert(solution.canPartition(given_nums) == expected_answer);

    return 0;
}

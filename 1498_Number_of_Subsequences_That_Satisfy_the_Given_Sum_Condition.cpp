//#1498 Number of Subsequences That Satisfy the Given Sum Condition - https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int result = 0;
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> power(n, 1);
        for(int i = 1; i < n; i++)
            power[i] = power[i - 1] * 2 % mod;
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        while(left <= right)
        {
            if(nums[left] + nums[right] <= target)
            {
                result = (result + power[right - left]) % mod;
                left++;
            }
            else
                right--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 5, 6, 7};
    int given_target = 9;
    int expected_answer = 4;
    assert(solution.numSubseq(given_nums, given_target) == expected_answer);

    given_nums = {2, 3, 3, 4, 6, 7};
    given_target = 12;
    expected_answer = 61;
    assert(solution.numSubseq(given_nums, given_target) == expected_answer);

    return 0;
}

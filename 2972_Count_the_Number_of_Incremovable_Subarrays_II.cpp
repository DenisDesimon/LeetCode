//#2972 Count the Number of Incremovable Subarrays II - https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        vector<int> right;
        right.push_back(nums.back());
        long long result = 0;
        for(int i = (int)nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] >= right.back())
                break;
            right.push_back(nums[i]);
        }
        if(right.size() == nums.size())
            return (long long)(nums.size() * (nums.size() + 1) / 2);
        reverse(right.begin(), right.end());
        int i = 0, left = -1;
        for(; i < (int)(nums.size() - right.size()); i++)
        {
            vector<int>::iterator greater = upper_bound(right.begin(), right.end(), nums[i]);
            if(left >= nums[i])
                break;
            left = nums[i];
            result += right.end() - greater;
        }
        result += right.size() + i;
        return result + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 4};
    int expected_answer = 10;
    assert(solution.incremovableSubarrayCount(given_nums) == expected_answer);

    given_nums = {8, 7, 6, 6};
    expected_answer = 3;
    assert(solution.incremovableSubarrayCount(given_nums) == expected_answer);

    return 0;
}

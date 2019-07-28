//#34 Find First and Last Position of Element in Sorted Array - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    int first_occur(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[left] != target)
            return -1;
        return left;
    }
public:
    vector<int> cheating(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if(lower == nums.end() || *lower != target)
            return {-1, -1};
        auto upper = upper_bound(nums.begin(), nums.end(), target);
            return {int(lower - nums.begin()), int(upper - nums.begin()) - 1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int left = -1, right = -1;
        left = first_occur(nums, target);
        if(left == -1)
            return {-1, -1};
        right = left;
        while(right + 1 < (int)nums.size() && nums[right] == nums[right  + 1])
            right++;
        return {left, right};
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 7, 7, 8, 8, 10};
    int given_target = 8;
    vector<int> expected_answer = {3, 4};
    assert(solution.cheating(given_nums, given_target) == expected_answer);
    assert(solution.searchRange(given_nums, given_target) == expected_answer);

    given_nums = {5, 7, 7, 8, 8, 10};
    given_target = 6;
    expected_answer = {-1, -1};
    assert(solution.cheating(given_nums, given_target) == expected_answer);
    assert(solution.searchRange(given_nums, given_target) == expected_answer);

    return 0;
}

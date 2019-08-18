//#153 Find Minimum in Rotated Sorted Array - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int result = nums[left];
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[left] <= nums[mid])
            {
                result = min(result, nums[left]);
                if(nums[mid] > nums[right])
                    left = mid + 1;
                else
                    break;
            }
            else
            {
                result = min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> given_nums = {2, 1};
    int expected_answer = 1;
    assert(solution.findMin(given_nums) == expected_answer);

    given_nums = {4, 5, 6, 7, 0, 1, 2};
    expected_answer = 0;
    assert(solution.findMin(given_nums) == expected_answer);

    return 0;
}

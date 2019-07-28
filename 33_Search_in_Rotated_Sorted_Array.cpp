//#33 Search in Rotated Sorted Array - https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            //right half is sorted
            else if(nums[mid] < nums[right])
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            //left half is sorted
            else
            {
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 5, 6, 7, 0, 1, 2};
    int given_target = 0;
    int expected_answer = 4;
    assert(solution.search(given_nums, given_target) == expected_answer);

    given_nums = {4, 5, 6, 7, 0, 1, 2};
    given_target = 3;
    expected_answer = -1;
    assert(solution.search(given_nums, given_target) == expected_answer);

    return 0;
}

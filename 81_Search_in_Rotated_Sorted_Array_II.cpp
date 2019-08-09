//#81 Search in Rotated Sorted Array II - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] == nums[left] && nums[mid] == nums[right])
                right--;
            else if(nums[mid] <= nums[right])
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if(target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
   Solution solution;
   vector<int> given_nums = {1, 1, 3, 1};
   int given_target = 3;
   bool expected_answer = true;
   assert(solution.search(given_nums, given_target) == expected_answer);

   given_nums = {2, 5, 6, 0, 0, 1, 2};
   given_target = 6;
   expected_answer = true;
   assert(solution.search(given_nums, given_target) == expected_answer);

   return 0;
}

//#26 Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size() == 0)
           return 0;
       int left = 0;
       for(int i = 1; i < (int)nums.size(); i++)
       {
           if(nums[i] != nums[left])
           {
               nums[++left] = nums[i];
           }
       }
       return left + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int  expected_answer = 5;
    assert(solution.removeDuplicates(given_nums) == expected_answer);

    given_nums = {1, 1};
    expected_answer = 1;
    assert(solution.removeDuplicates(given_nums) == expected_answer);

    return 0;
}

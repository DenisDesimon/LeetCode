//#3011 Find if Array Can Be Sorted - https://leetcode.com/problems/find-if-array-can-be-sorted/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int countSetBits(int num){
        int result = 0;
        while(num)
        {
            result++;
            num &= (num - 1);
        }
        return result;
    }
    bool canSortArray(vector<int>& nums) {
        int previous_max = 0;
        int current_max = nums.front();
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(countSetBits(nums[i]) != countSetBits(nums[i - 1]))
            {
                previous_max = current_max;
            }
            if(previous_max > nums[i])
                return false;
            current_max = max(current_max, nums[i]);
        }
        return true;
    }
};

int main()
{
    Solution solution;

    vector<int> given_nums = {8, 4, 2, 30, 15};
    bool expected_answer = true;
    assert(solution.canSortArray(given_nums) == expected_answer);

    given_nums = {3, 16, 8, 4, 2};
    expected_answer = false;
    assert(solution.canSortArray(given_nums) == expected_answer);

    return 0;
}

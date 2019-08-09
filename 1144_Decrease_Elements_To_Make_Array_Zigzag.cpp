//#1144 Decrease Elements To Make Array Zigzag - https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int result_odd = 0, result_even = 0, pre_even = nums[0];
        for(int i = 1; i < (int)nums.size(); i += 2)
        {
            if(i + 1 < (int)nums.size())
            {
                if(nums[i] >=  pre_even || nums[i] >= nums[i + 1])
                      result_even += nums[i] - min(pre_even, nums[i + 1]) + 1;
                pre_even = nums[i + 1];
                if(nums[i - 1] >= nums[i])
                    {
                        result_odd += nums[i - 1] - nums[i] + 1;
                        nums[i - 1] = nums[i] - 1;
                    }
                 if(nums[i + 1] >= nums[i])
                    {
                        result_odd += nums[i + 1] - nums[i] + 1;
                        nums[i + 1] = nums[i] - 1;
                    }
            }
            else
            {
                if(nums[i] >=  pre_even)
                      result_even += nums[i] - pre_even + 1;
                    if(nums[i - 1] >= nums[i])
                    {
                        result_odd += nums[i - 1] - nums[i] + 1;
                        nums[i - 1] = nums[i] - 1;
                    }
            }
        }
        return min(result_even, result_odd);

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {9, 6, 1, 6, 2};
    int expected_answer = 4;
    assert(solution.movesToMakeZigzag(given_nums) == expected_answer);

    given_nums = {1, 2, 3};
    expected_answer = 2;
    assert(solution.movesToMakeZigzag(given_nums) == expected_answer);

    return 0;
}

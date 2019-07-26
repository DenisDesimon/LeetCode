//#16 3Sum Closest - https://leetcode.com/problems/3sum-closest/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        if(nums.size() < 4)
            return accumulate(nums.begin(), nums.begin() + 3, 0);
        if(nums[0] > target)
        {
            if(nums[0] >= 0)
                return accumulate(nums.begin(), nums.begin() + 3, 0);
            else
            {
                int left = 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    int cur_sum = nums[0] + nums[left] + nums[right];
                    if(cur_sum == target)
                        return target;
                    else if(cur_sum > target)
                        right--;
                    else if(cur_sum < target)
                        left++;
                    if(result == INT_MAX || abs(result - target) > abs(cur_sum - target))
                        result = cur_sum;
                }
            }
        }
        for(int i = 0; i + 2 < (int)nums.size(); i++)
        {
            if(nums[i] > target)
            {
                break;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int cur_sum = nums[i] + nums[left] + nums[right];
                if(cur_sum == target)
                    return target;
                else if(cur_sum > target)
                    right--;
                else if(cur_sum < target)
                    left++;
                if(result == INT_MAX || abs(result - target) > abs(cur_sum - target))
                    result = cur_sum;
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-1, 2, 1, -4};
    int given_target = 1;
    int expected_answer = 2;
    assert(solution.threeSumClosest(given_nums, given_target) == expected_answer);

    given_nums = {1, 2, 5, 10, 11};
    given_target = 12;
    expected_answer = 13;
    assert(solution.threeSumClosest(given_nums, given_target) == expected_answer);

    return 0;
}

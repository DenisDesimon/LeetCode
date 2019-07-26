//#18 4Sum - https://leetcode.com/problems/4sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i + 3 < (int)nums.size(); i++)
        {
            if(nums[i] >= 0 && nums[i] > target)
                break;
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j + 2 < (int)nums.size(); j++)
            {
                if(nums[i] >= 0 && nums[i] + nums[j] > target)
                    break;
                if(j != i + 1 &&  nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = (int)nums.size() - 1;
                while(left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    if(sum >= target)
                    {
                        while(--right > left && nums[right + 1] == nums[right]);
                    }
                    if(sum < target)
                    {
                        while(++left < right && nums[left - 1] == nums[left]);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 0, -1, 0, -2, 2};
    int given_target = 0;
    vector<vector<int>> expected_answer = {{-2, -1, 1, 2}, {-2,  0, 0, 2}, {-1,  0, 0, 1}};
    assert(solution.fourSum(given_nums, given_target) == expected_answer);

    return 0;
}

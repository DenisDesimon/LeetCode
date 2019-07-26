//#15 3Sum - https://leetcode.com/problems/3sum/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i + 2 < (int)nums.size(); i++)
        {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = (int)nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                    result.push_back({nums[i], nums[left], nums[right]});
                if(nums[i] + nums[left] + nums[right] >= 0)
                {
                    while(--right > left && nums[right + 1] == nums[right]);

                }
                if(nums[i] + nums[left] + nums[right] < 0)
                {
                    while(++left < right && nums[left - 1] == nums[left]);

                }
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> given_nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected_answer = {{-1, -1, 2}, {-1, 0, 1}};
    assert(solution.threeSum(given_nums) == expected_answer);

    return 0;
}

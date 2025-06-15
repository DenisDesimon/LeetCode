//#2962 Count Subarrays Where Max Element Appears at Least K Times - https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = INT_MIN;
        for(auto &num: nums)
            maxNum = max(maxNum, num);
        int left = 0, count = 0;
        long long result = 0;
        for(int right = 0; right < (int)nums.size(); right++)
        {
            if(nums[right] == maxNum)
                count++;
            while(count == k)
            {
                result += nums.size() - right;
                count -= nums[left] == maxNum ? 1 : 0;
                left++;
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;

    vector<int> given_nums = {1, 3, 2, 3, 3};
    int given_k = 2;
    long long expected_answer = 6;
    assert(solution.countSubarrays(given_nums, given_k) == expected_answer);


    given_nums = {1, 4, 2, 1};
    given_k = 3;
    expected_answer = 0;
    assert(solution.countSubarrays(given_nums, given_k) == expected_answer);


    return 0;
}

//#209 Minimum Size Subarray Sum - https://leetcode.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX, left = 0, sum = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            sum += nums[i];
            while(sum >= s)
            {
                result = min(result, i - left + 1);
                sum -= nums[left++];
            }
        }
        return result == INT_MAX ? 0 : result;

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 3, 1, 2, 4, 3};
    int given_target = 7;
    int  expected_answer = 2;
    assert(solution.minSubArrayLen(given_target, given_nums) == expected_answer);

    given_nums = {1, 3, 2, 5, 1, 2, 3};
    given_target = 19;
    expected_answer = 0;
    assert(solution.minSubArrayLen(given_target, given_nums) == expected_answer);

    return 0;
}

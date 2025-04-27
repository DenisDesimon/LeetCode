//#3392 Count Subarrays of Length Three With a Condition - https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for(int i = 1; i < (int)nums.size() - 1; i++)
        {
            if(nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, -4, -4};
    long long expected_answer = 0;
    assert(solution.countSubarrays(given_nums) == expected_answer);

    given_nums = {1, 2, 1, 4, 1};
    expected_answer = 1;
    assert(solution.countSubarrays(given_nums) == expected_answer);

    return 0;
}

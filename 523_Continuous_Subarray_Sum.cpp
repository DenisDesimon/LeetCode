//#523 Continuous Subarray Sum - https://leetcode.com/problems/continuous-subarray-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty())
            return false;
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            sum += nums[i];
            if(k != 0)
                sum %= k;
            if(hash.count(sum))
            {
                if(i - hash[sum] > 1)
                    return true;
            }
            else
                hash[sum] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {23, 2, 4, 6, 7};
    int given_k = 6;
    bool expected_answer = true;
    assert(solution.checkSubarraySum(given_nums, given_k) == expected_answer);

    given_nums = {23, 2, 4, 6, 7};
    given_k = 0;
    expected_answer = false;
    assert(solution.checkSubarraySum(given_nums, given_k) == expected_answer);

    return 0;
}

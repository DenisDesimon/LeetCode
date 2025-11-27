//#3381 Maximum Subarray Sum With Length Divisible by K - https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> leftSubArrayMin(k, LLONG_MAX / 2);
        long long prefixSum = 0;
        leftSubArrayMin[k - 1] = 0;
        long long result = LLONG_MIN;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            prefixSum += nums[i];
            result = max(result, prefixSum - leftSubArrayMin[i % k]);
            leftSubArrayMin[i % k] = min(leftSubArrayMin[i % k], prefixSum);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {-1, -2, -3, -4, -5};
    int givenK = 4;
    int expectedAnswer = -10;
    assert(solution.maxSubarraySum(givenNums, givenK) == expectedAnswer);

    givenNums = {-5, 1, 2, -3, 4};
    givenK = 2;
    expectedAnswer = 4;
    assert(solution.maxSubarraySum(givenNums, givenK) == expectedAnswer);

    return 0;
}

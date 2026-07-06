//#3976 Maximum Subarray Sum After Multiplier - https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    long long maxSum(vector<int> &nums, vector<long long> &mod){
        long long result = INT_MIN;
        long long sumNotMod = INT_MIN;
        long long sumModStarted = INT_MIN;
        long long sumModEnded = INT_MIN;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            long long curNum = nums[i];
            long long curMod = mod[i];
            long long nextSumNotMod = max(sumNotMod + curNum, curNum);
            long long nextSumModStarted = max({curMod, sumModStarted + curMod, sumNotMod + curMod});
            long long nextSumModEnded = max({sumModEnded + curNum, sumModStarted + curNum});
            sumNotMod = nextSumNotMod;
            sumModStarted = nextSumModStarted;
            sumModEnded = nextSumModEnded;
            result = max({result, sumModStarted, sumModEnded});
        }
        return result;
    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> numsMult(n);
        vector<long long> numsDiv(n);
        for(int i = 0; i < n; i++)
        {
            numsMult[i] = (long long)nums[i] * k;
            if(nums[i] < 0)
                numsDiv[i] = -((-nums[i]) / k);
            else
                numsDiv[i] = nums[i] / k;
        }
        return max(maxSum(nums, numsMult), maxSum(nums, numsDiv));
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, -2, 3, 4, -5};
    int givenK = 2;
    int expectedAnswer = 14;
    assert(solution.maxSubarraySum(givenNums, givenK) == expectedAnswer);

    givenNums = {-5, -4, -3};
    givenK = 2;
    expectedAnswer = -1;
    assert(solution.maxSubarraySum(givenNums, givenK) == expectedAnswer);

    return 0;
}

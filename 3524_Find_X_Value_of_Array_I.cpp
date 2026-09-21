//#3524 Find X Value of Array I - https://leetcode.com/problems/find-x-value-of-array-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        vector<long long> dp(k);
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            vector<long long> cur(k);
            cur[nums[i] % k]++;
            for(int rem = 0; rem < k; rem++)
                cur[(long long)nums[i] * rem % k] += dp[rem];
            dp = move(cur);
            for(int rem = 0; rem < k; rem++)
                result[rem] += dp[rem];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4, 5};
    int givenK = 3;
    vector<long long> expectedAnswer = {9, 2, 4};
    assert(solution.resultArray(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 2, 4, 8, 16, 32};
    givenK = 4;
    expectedAnswer = {18, 1, 2, 0};
    assert(solution.resultArray(givenNums, givenK) == expectedAnswer);


    return 0;
}

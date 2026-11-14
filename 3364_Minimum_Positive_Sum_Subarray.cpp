//#3364 Minimum Positive Sum Subarray  - https://leetcode.com/problems/minimum-positive-sum-subarray/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int result = INT_MAX;
        int n = nums.size();
        vector<int> prefix(n + 1);
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        for(int len = l; len <= r; len++)
        {
            for(int i = 0; i + len <= n; i++)
            {
                int cur = prefix[i + len] - prefix[i];
                if(cur > 0)
                    result = min(result, cur);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, -2, 1, 4};
    int givenL = 2;
    int givenR = 3;
    int expectedAnswer = 1;
    assert(solution.minimumSumSubarray(givenNums, givenL, givenR) == expectedAnswer);

    givenNums = {1, 2, 3, 4};
    givenL = 2;
    givenR = 4;
    expectedAnswer = 3;
    assert(solution.minimumSumSubarray(givenNums, givenL, givenR) == expectedAnswer);

    return 0;
}

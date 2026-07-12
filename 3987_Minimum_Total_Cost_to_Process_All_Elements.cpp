//#3987 Minimum Total Cost to Process All Elements - https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long result = 0;
        long long count = 0;
        long long resources = k;
        int MOD = 1e9 + 7;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] > resources)
            {
                long long left = nums[i] - resources;
                long long times = (left + k - 1) / k % MOD;
                result = (result + (2 * count + times + 1) % MOD * times / 2) % MOD;
                count += times;
                resources += times * k;
            }
            resources -= nums[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4};
    int givenK = 4;
    int expectedAnswer = 3;
    assert(solution.minimumCost(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 1, 7, 14};
    givenK = 4;
    expectedAnswer = 15;
    assert(solution.minimumCost(givenNums, givenK) == expectedAnswer);

    return 0;
}

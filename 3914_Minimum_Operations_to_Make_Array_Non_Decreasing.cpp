//#3914 Minimum Operations to Make Array Non Decreasing - https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long result = 0;
        for(int i = 1; i < (int)nums.size(); i++)
            result += max(0, nums[i - 1] - nums[i]);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 3, 2, 1};
    long long expectedAnswer = 2;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    givenNums = {5 ,1, 2, 3};
    expectedAnswer = 4;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    return 0;
}

//#396 Rotate Function - https://leetcode.com/problems/rotate-function/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int func = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            func += nums[i] * i;
        }
        int result = func;
        for(int i = n - 1; i > 0; i--)
        {
            func += sum - nums[i] * n;
            result = max(result, func);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {4, 3, 2, 6};
    int expectedAnswer = 26;
    assert(solution.maxRotateFunction(givenNums) == expectedAnswer);

    givenNums = {100};
    expectedAnswer = 0;
    assert(solution.maxRotateFunction(givenNums) == expectedAnswer);

    return 0;
}

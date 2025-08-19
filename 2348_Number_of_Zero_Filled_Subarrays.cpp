//#2348 Number of Zero-Filled Subarrays - https://leetcode.com/problems/number-of-zero-filled-subarrays/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeroCount = 0, result = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] == 0)
                zeroCount++;
            else if(zeroCount)
            {
                result += (1 + zeroCount) * zeroCount / 2;
                zeroCount = 0;
            }
        }
        result += (1 + zeroCount) * zeroCount / 2;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 0, 0, 2, 0, 0, 4};
    long long expectedAnswer = 6;
    assert(solution.zeroFilledSubarray(givenNums) == expectedAnswer);

    givenNums = {0, 0, 0, 2, 0, 0};
    expectedAnswer = 9;
    assert(solution.zeroFilledSubarray(givenNums) == expectedAnswer);

    return 0;
}

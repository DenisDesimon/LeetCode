//#3640 Trionic Array II - https://leetcode.com/problems/trionic-array-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long result = LLONG_MIN;
        long long countLeft = 0, countMid = 0, countTotal = 0;
        bool isIncreasing = false, isDecreasing = false, isTrionic = false;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                countLeft = 0;
                countMid = 0;
                countTotal = 0;
                isIncreasing = false;
                isDecreasing = false;
                isTrionic = false;
                continue;
            }
            else if(nums[i] > nums[i - 1])
            {
                if(isDecreasing)
                {
                    countTotal += countMid;
                    countMid = 0;
                    isDecreasing = false;
                    isTrionic = true;
                }
                if(isTrionic)
                {
                    countTotal += nums[i];
                    result = max(result, countTotal);
                }
                if(!isIncreasing)
                    countLeft += nums[i - 1];
                countLeft = max(countLeft + nums[i], (long long)nums[i] + nums[i - 1]);
                isIncreasing = true;
            }
            else if(isIncreasing || isDecreasing)
            {
                countMid += countLeft + nums[i];
                countLeft = 0;
                countTotal = 0;
                isDecreasing = true;
                isIncreasing = false;
                isTrionic = false;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {0, -2, -1, -3, 0, 2, -1};
    long long expectedAnswer = -4;
    assert(solution.maxSumTrionic(givenNums) == expectedAnswer);

    givenNums = {1, 4, 2, 7};
    expectedAnswer = 14;
    assert(solution.maxSumTrionic(givenNums) == expectedAnswer);


    return 0;
}

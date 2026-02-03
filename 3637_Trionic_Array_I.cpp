//#3637 Trionic Array I - https://leetcode.com/problems/trionic-array-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0] >= nums[1])
            return false;
        bool isDecreasing = false, isIncreasing = false;
        for(int i = 2; i < (int)nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
                return false;
            if(nums[i] < nums[i - 1])
            {
                if(isIncreasing)
                    return false;
                isDecreasing = true;
            }
            else if(isDecreasing)
            {
                isIncreasing = true;
                isDecreasing = false;
            }
        }
        return isIncreasing;
    }
};


int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 5, 4, 2, 6};
    bool expectedAnswer = true;
    assert(solution.isTrionic(givenNums) == expectedAnswer);

    givenNums = {8, 9, 4, 6, 1};
    expectedAnswer = false;
    assert(solution.isTrionic(givenNums) == expectedAnswer);


    return 0;
}

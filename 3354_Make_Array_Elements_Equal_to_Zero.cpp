//#3354 Make Array Elements Equal to Zero - https://leetcode.com/problems/make-array-elements-equal-to-zero/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int right = 0;
        int left = 0;
        for(int i = n - 1; i >= 0; i--)
            right += nums[i];
        for(int i = 0; i < n; i++)
        {
            left += nums[i];
            right -= nums[i];
            if(nums[i] == 0)
            {
                if(left == right)
                    result += 2;
                if(abs(left - right) == 1)
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 0, 2, 0, 3};
    int expectedAnswer = 2;
    assert(solution.countValidSelections(givenNums) == expectedAnswer);

    givenNums = {0};
    expectedAnswer = 2;
    assert(solution.countValidSelections(givenNums) == expectedAnswer);

    return 0;
}

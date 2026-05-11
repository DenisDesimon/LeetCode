//#3925 Concatenate Array With Reverse - https://leetcode.com/problems/concatenate-array-with-reverse/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--)
        {
             nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 3};
    vector<int> expectedAnswer = {1, 2, 3, 3, 2, 1};
    assert(solution.concatWithReverse(givenNums) == expectedAnswer);

    givenNums = {1};
    expectedAnswer = {1, 1};
    assert(solution.concatWithReverse(givenNums) == expectedAnswer);

    return 0;
}

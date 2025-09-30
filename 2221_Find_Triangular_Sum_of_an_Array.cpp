//#2221 Find Triangular Sum of an Array - https://leetcode.com/problems/find-triangular-sum-of-an-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int i = nums.size(); i > 1; i--)
        {
            for(int j = 0; j < i - 1; j++)
            {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums.front();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4, 5};
    int expectedAnswer = 8;
    assert(solution.triangularSum(givenNums) == expectedAnswer);

    givenNums = {3};
    expectedAnswer = 3;
    assert(solution.triangularSum(givenNums) == expectedAnswer);

    return 0;
}

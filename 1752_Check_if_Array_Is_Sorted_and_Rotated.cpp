//#1752 Check if Array Is Sorted and Rotated - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated = false;
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                if(isRotated || nums.front() < nums.back())
                    return false;
                isRotated = true;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {3, 4, 5, 1, 2};
    bool expectedAnswer = true;
    assert(solution.check(givenNums) == expectedAnswer);

    givenNums  = {2, 1, 3, 4};
    expectedAnswer = false;
    assert(solution.check(givenNums) == expectedAnswer);

    return 0;
}

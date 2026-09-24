//#3550 Smallest Index With Digit Sum Equal to Index - https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); i++)
        {
            int sum = 0;
            while(nums[i])
            {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }
            if(sum == i)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 10, 11};
    int expectedAnswer = 1;
    assert(solution.smallestIndex(givenNums) == expectedAnswer);

    givenNums = {1, 3, 2};
    expectedAnswer = 2;
    assert(solution.smallestIndex(givenNums) == expectedAnswer);


    return 0;
}

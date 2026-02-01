//#3010 Divide an Array Into Subarrays With Minimum Cost I - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result = nums.front();
        int minFirst = INT_MAX, minSecond = INT_MAX;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] < minFirst)
            {
                minSecond = minFirst;
                minFirst = nums[i];
            }else if(nums[i] < minSecond)
                minSecond = nums[i];
        }
        return result + minFirst + minSecond;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 12};
    int expectedAnswer = 6;
    assert(solution.minimumCost(givenNums) == expectedAnswer);

    givenNums = {10, 3, 1, 1};
    expectedAnswer = 12;
    assert(solution.minimumCost(givenNums) == expectedAnswer);


    return 0;
}

//#3507 Minimum Pair Removal to Sort Array I - https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result = 0;
        while(true)
        {
            bool isDecreasing = true;
            pair<int, int> minPos = {INT_MAX, 1};
            for(int i = 1; i < (int)nums.size(); i++)
            {
                if(minPos.first > nums[i] + nums[i - 1])
                    minPos = {nums[i] + nums[i - 1], i};
                if(nums[i] < nums[i - 1])
                    isDecreasing = false;
            }
            if(isDecreasing)
                break;
            result++;
            nums.erase(nums.begin() + minPos.second);
            nums[minPos.second - 1] = minPos.first;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {5, 2, 3, 1};
    int expectedAnswer = 2;
    assert(solution.minimumPairRemoval(givenNums) == expectedAnswer);

    givenNums = {1, 2, 2};
    expectedAnswer = 0;
    assert(solution.minimumPairRemoval(givenNums) == expectedAnswer);

    return 0;
}

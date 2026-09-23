//#1658 Minimum Operations to Reduce X to Zero - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sumMid = -x;
        int n = nums.size();
        for(auto &num : nums)
            sumMid += num;
        if(sumMid < 0)
            return -1;
        if(sumMid == 0)
            return n;
        int left = 0, curMid = 0, result = -1;
        for(int right = 0; right < n; right++)
        {
            curMid += nums[right];
            while(curMid > sumMid)
                curMid -= nums[left++];
            if(curMid == sumMid)
                result = max(result, right - left + 1);
        }
        return result != -1 ? n - result : -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 4, 2, 3};
    int givenX = 5;
    int expectedAnswer = 2;
    assert(solution.minOperations(givenNums, givenX) == expectedAnswer);

    givenNums = {3, 2, 20, 1, 1, 3};
    givenX = 10;
    expectedAnswer = 5;
    assert(solution.minOperations(givenNums, givenX) == expectedAnswer);


    return 0;
}

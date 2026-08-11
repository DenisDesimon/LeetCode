//#2996 Smallest Missing Integer Greater Than Sequential Prefix Sum - https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        long long mask = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            mask |= 1LL << nums[i];
        int sum = nums.front();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i - 1] + 1)
                break;
            sum += nums[i];
        }
        for(int i = sum; i <= 51; i++)
        {
            if(!(mask & 1LL << i))
                return i;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 2, 5};
    int expectedAnswer = 6;
    assert(solution.missingInteger(givenNums) == expectedAnswer);

    givenNums = {37, 1, 2, 9, 5, 8, 5, 2, 9, 4};
    expectedAnswer = 38;
    assert(solution.missingInteger(givenNums) == expectedAnswer);

    return 0;
}

//#3942 Minimum Operations to Sort a Permutation - https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc = 1, desc = 1;
        for(int i = 1; i < n; i++)
        {
            asc += nums[i] == (nums[i - 1] + 1) % n;
            desc += nums[i - 1] == (nums[i] + 1) % n;
        }
        if(asc == n && nums.front() == 0)
            return 0;
        if(asc == n)
            return min(n - nums.front(), nums.front() + 2);
        if(desc == n)
            return min(nums.back(), n - nums.back()) + 1;
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 0, 1, 3};
    int expectedAnswer = -1;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    givenNums = {1, 0, 2};
    expectedAnswer = 2;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    return 0;
}

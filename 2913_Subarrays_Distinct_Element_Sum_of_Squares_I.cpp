//#2913 Subarrays Distinct Element Sum of Squares I - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
#include <iostream>
#include <cassert>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            bitset<101> count;
            for(int j = i; j < n; j++)
            {
                count.set(nums[j]);
                result += count.count() * count.count();
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 1};
    int expectedAnswer = 15;
    assert(solution.sumCounts(givenNums) == expectedAnswer);

    givenNums  = {1, 1};
    expectedAnswer = 3;
    assert(solution.sumCounts(givenNums) == expectedAnswer);

    return 0;
}

//#3397 Maximum Number of Distinct Elements After Operations - https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0, prev = INT_MIN;
        for(auto &num : nums)
        {
            auto cur = min(max(prev + 1, num - k), num + k);
            if(cur > prev)
            {
                prev = cur;
                result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 2, 3, 3, 4};
    int givenk = 2;
    int expectedAnswer = 6;
    assert(solution.maxDistinctElements(givenNums, givenk) == expectedAnswer);

    givenNums = {4, 4, 4, 4};
    givenk = 1;
    expectedAnswer = 3;
    assert(solution.maxDistinctElements(givenNums, givenk) == expectedAnswer);

    return 0;
}

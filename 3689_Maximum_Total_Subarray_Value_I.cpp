//#3689 Maximum Total Subarray Value I - https://leetcode.com/problems/maximum-total-subarray-value-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(auto &num : nums)
        {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        return (long long)k * (maxNum - minNum);
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 2};
    int givenK = 2;
    long long expectedAnswer = 4;
    assert(solution.maxTotalValue(givenNums, givenK) == expectedAnswer);

    givenNums = {4, 2, 5, 1};
    givenK = 3;
    expectedAnswer = 12;
    assert(solution.maxTotalValue(givenNums, givenK) == expectedAnswer);

    return 0;
}

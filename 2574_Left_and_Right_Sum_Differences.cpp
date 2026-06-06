//#2574 Left and Right Sum Differences - https://leetcode.com/problems/left-and-right-sum-differences/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixLeft(n);
        for(int i = 1; i < n; i++)
        {
            prefixLeft[i] = prefixLeft[i - 1] + nums[i - 1];
        }
        int sumRight = 0;
        vector<int> result(n);
        for(int i = n - 1; i >= 0; i--)
        {
            result[i] = abs(sumRight - prefixLeft[i]);
            sumRight += nums[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {10, 4, 8, 3};
    vector<int> expectedAnswer = {15, 1, 11, 22};
    assert(solution.leftRightDifference(givenNums) == expectedAnswer);

    givenNums = {1};
    expectedAnswer = {0};
    assert(solution.leftRightDifference(givenNums) == expectedAnswer);

    return 0;
}

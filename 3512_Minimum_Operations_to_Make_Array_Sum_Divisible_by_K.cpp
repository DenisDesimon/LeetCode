//#3512 Minimum Operations to Make Array Sum Divisible by K - https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &num : nums)
            sum += num;
        return sum % k;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 9, 7};
    int givenK = 5;
    int expectedAnswer = 4;
    assert(solution.minOperations(givenNums, givenK) == expectedAnswer);

    givenNums = {4, 1, 3};
    givenK = 4;
    expectedAnswer = 0;
    assert(solution.minOperations(givenNums, givenK) == expectedAnswer);

    return 0;
}

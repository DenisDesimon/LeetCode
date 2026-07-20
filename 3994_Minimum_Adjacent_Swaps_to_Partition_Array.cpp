//#3994 Minimum Adjacent Swaps to Partition Array - https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int MOD = 1e9 + 7;
        long long result = 0;
        long long count[3] = {0, 0, 0};
        int group;
        for(auto &num : nums)
        {
            if(num < a)
                group = 0;
            else if(num > b)
                group = 2;
            else
                group = 1;
            for(int i = group + 1; i < 3; i++)
                result += count[i];
            count[group]++;
        }
        return result % MOD;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3 ,2, 4, 5, 6};
    int givenA = 3;
    int givenB = 4;
    int expectedAnswer = 1;
    assert(solution.minAdjacentSwaps(givenNums, givenA, givenB) == expectedAnswer);

    givenNums = {9, 7, 5, 3};
    givenA = 4;
    givenB = 8;
    expectedAnswer = 5;
    assert(solution.minAdjacentSwaps(givenNums, givenA, givenB) == expectedAnswer);

    return 0;
}

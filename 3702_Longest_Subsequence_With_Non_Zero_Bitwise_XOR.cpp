//#3702 Longest Subsequence With Non-Zero Bitwise XOR - https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        bool isAllZero = true;
        for(auto &num : nums)
        {
            sum ^= num;
            if(num)
                isAllZero = false;
        }
        if(sum)
            return n;
        return isAllZero ? 0 : n - 1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3};
    int expectedAnswer = 2;
    assert(solution.longestSubsequence(givenNums) == expectedAnswer);

    givenNums = {2, 3, 4};
    expectedAnswer = 3;
    assert(solution.longestSubsequence(givenNums) == expectedAnswer);


    return 0;
}

//#3201 Find the Maximum Length of Valid Subsequence I - https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cntOne = 0, cntZero = 0, cntShift = 0, lastMod = nums.front() % 2;
        for(auto &num : nums)
        {
           num % 2 ? cntZero++ : cntOne++;
           if(num % 2 == lastMod)
           {
               cntShift++;
               lastMod = !lastMod;
           }
        }
        return max(cntShift, max(cntOne, cntZero));
    }
};

int main()
{
    Solution solution;

    vector<int> givenNums = {1, 2, 1, 1, 2, 1, 2};
    int expectedAnswer = 6;
    assert(solution.maximumLength(givenNums) == expectedAnswer);

    givenNums = {1, 4, 2, 3, 1, 4};
    expectedAnswer = 4;
    assert(solution.maximumLength(givenNums) == expectedAnswer);

    return 0;
}

//#1979 Find Greatest Common Divisor of Array - https://leetcode.com/problems/find-greatest-common-divisor-of-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(auto &num : nums)
        {
            maxNum = max(num, maxNum);
            minNum = min(num, minNum);
        }
        while(minNum != 0)
        {
            int temp = minNum;
            minNum = maxNum % minNum;
            maxNum = temp;
        }
        return maxNum;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 5, 6, 9, 10};
    int expectedAnswer = 2;
    assert(solution.findGCD(givenNums) == expectedAnswer);

    givenNums = {7, 5, 6, 8, 3};
    expectedAnswer = 1;
    assert(solution.findGCD(givenNums) == expectedAnswer);

    return 0;
}

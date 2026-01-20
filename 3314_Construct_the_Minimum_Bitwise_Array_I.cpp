//#3314 Construct the Minimum Bitwise Array I - https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(auto &num : nums)
        {
            int cur = -1;
            int carry = 1;
            while((num & carry))
            {
                cur = num - carry;
                carry <<= 1;
            }
            result.push_back(cur);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {2, 3, 5, 7};
    vector<int> expectedAnswer = {-1, 1, 4, 3};
    assert(solution.minBitwiseArray(givenNums) == expectedAnswer);

    givenNums = {11, 13, 31};
    expectedAnswer = {9, 12, 15};
    assert(solution.minBitwiseArray(givenNums) == expectedAnswer);

    return 0;
}

//#3315 Construct the Minimum Bitwise Array II - https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(auto & num : nums)
        {
            int carry = 1;
            int res = -1;
            while((num & carry))
            {
                res = num - carry;
                carry <<= 1;
            }
            result.push_back(res);
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

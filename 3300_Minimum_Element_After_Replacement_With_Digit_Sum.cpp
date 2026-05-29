//#3300 Minimum Element After Replacement With Digit Sum - https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for(auto &num : nums)
        {
            int sum = 0;
            while(num)
            {
                sum += num % 10;
                num /= 10;
            }
            result = min(result, sum);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {10, 12, 13, 14};
    int expectedAnswer = 1;
    assert(solution.minElement(givenNums) == expectedAnswer);

    givenNums  = {1, 2, 3, 4};
    expectedAnswer = 1;
    assert(solution.minElement(givenNums) == expectedAnswer);

    return 0;
}

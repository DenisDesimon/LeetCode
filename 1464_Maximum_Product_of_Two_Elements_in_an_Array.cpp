//#1464 Maximum Product of Two Elements in an Array - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = 0, secondMax = 0;
        for(auto &num : nums)
        {
            if(num >= firstMax)
            {
                secondMax = firstMax;
                firstMax = num;
            }else
                secondMax = max(secondMax, num);
        }
        return (firstMax - 1) * (secondMax - 1);
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 4, 5, 2};
    int expectedAnswer = 12;
    assert(solution.maxProduct(givenNums) == expectedAnswer);

    givenNums = {1, 5, 4, 5};
    expectedAnswer = 16;
    assert(solution.maxProduct(givenNums) == expectedAnswer);

    return 0;
}

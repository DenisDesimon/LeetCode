//#628 Maximum Product of Three Numbers - https://leetcode.com/problems/maximum-product-of-three-numbers/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxFirst = INT_MIN, maxSecond = INT_MIN, maxThird = INT_MIN;
        int minFirst = INT_MAX, minSecond = INT_MAX;
        for(auto &num : nums)
        {
            if(num >= maxFirst)
            {
                maxThird = maxSecond;
                maxSecond = maxFirst;
                maxFirst = num;
            }else if(num >= maxSecond)
            {
                maxThird = maxSecond;
                maxSecond = num;
            }
            else
                maxThird = max(num, maxThird);
            if(num <= minFirst)
            {
                minSecond = minFirst;
                minFirst = num;
            }else
                minSecond = min(minSecond, num);
        }
        return max(maxFirst * maxSecond * maxThird, maxFirst * minFirst * minSecond);
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4};
    int expectedAnswer = 24;
    assert(solution.maximumProduct(givenNums) == expectedAnswer);

    givenNums = {-1, -2, -3};
    expectedAnswer = -6;
    assert(solution.maximumProduct(givenNums) == expectedAnswer);

    return 0;
}

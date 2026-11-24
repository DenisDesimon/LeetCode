//#3411 Maximum Subarray With Equal Products - https://leetcode.com/problems/maximum-subarray-with-equal-products/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    long long gcd(long long left, long long right)
    {
        while(right)
        {
            int temp = right;
            right = left % right;
            left = temp;
        }
        return left;
    }
    long long lcm(long long left, long long right)
    {
        if(left == 0 || right == 0)
            return 0;
        return (left / gcd(left, right)) * right;
    }
public:
    int maxLength(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            long long product = 1;
            long long curGcd = nums[i];
            long long curLcm = 1;
            for(int j = i; j < n; j++)
            {
                product *= nums[j];
                curGcd = gcd(curGcd, nums[j]);
                curLcm = lcm(curLcm, nums[j]);
                if(product > curGcd * curLcm)
                    break;
                if(product == curGcd * curLcm)
                    result = max(result, j - i + 1);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 1, 2, 1, 1, 1};
    long long expectedAnswer = 5;
    assert(solution.maxLength(givenNums) == expectedAnswer);

    givenNums = {2, 3, 4, 5, 6};
    expectedAnswer = 3;
    assert(solution.maxLength(givenNums) == expectedAnswer);

    return 0;
}

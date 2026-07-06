//#3974 Maximum Total Sum of K Selected Elements - https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long result = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < k; i++)
        {
            result += (long long)nums[i] * mul;
            if(mul > 1)
                mul--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {6, 1, 2, 9};
    int givenK = 3;
    int givenMul = 2;
    int expectedAnswer = 26;
    assert(solution.maxSum(givenNums, givenK, givenMul) == expectedAnswer);

    givenNums = {3, 7, 5, 2};
    givenK = 2;
    givenMul = 4;
    expectedAnswer = 43;
    assert(solution.maxSum(givenNums, givenK, givenMul) == expectedAnswer);

    return 0;
}

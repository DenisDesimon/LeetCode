//#3867 Sum of GCD of Formed Pairs - https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    int gcd(int a, int b){
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        long long result = 0;
        int maxNum = INT_MIN;
        for(auto &num : nums)
        {
            maxNum = max(maxNum, num);
            num = gcd(maxNum, num);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n / 2; i++)
        {
            result += gcd(nums[i], nums[n - 1 - i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 6, 4};
    long long expectedAnswer = 2;
    assert(solution.gcdSum(givenNums) == expectedAnswer);

    givenNums = {3, 6, 2, 8};
    expectedAnswer = 5;
    assert(solution.gcdSum(givenNums) == expectedAnswer);

    return 0;
}

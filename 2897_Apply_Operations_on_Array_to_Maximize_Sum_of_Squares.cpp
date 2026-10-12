//#2897 Apply Operations on Array to Maximize Sum of Squares  - https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int count[32] = {0};
        int MOD = 1e9 + 7;
        for(auto &num : nums)
        {
            for(int i = 0; i < 32; i++)
            {
                if(num & (1 << i))
                    count[i]++;
            }
        }
        long long result = 0;
        while(k--)
        {
            long long cur = 0;
            for(int i = 0; i < 32; i++)
            {
                if(count[i])
                {
                    cur |= 1LL << i;
                    count[i]--;
                }
            }
            result = (result + cur * cur % MOD) % MOD;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {2, 6, 5, 8};
    int givenK = 2;
    int expectedAnswer = 261;
    assert(solution.maxSum(givenNums, givenK) == expectedAnswer);

    givenNums  = {4, 5, 4, 7};
    givenK = 3;
    expectedAnswer = 90;
    assert(solution.maxSum(givenNums, givenK) == expectedAnswer);

    return 0;
}

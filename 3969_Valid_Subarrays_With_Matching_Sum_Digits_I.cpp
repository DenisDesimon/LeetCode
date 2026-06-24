//#3969 Valid Subarrays With Matching Sum Digits I - https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> prefix(n + 1);
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                long long subSum = prefix[i + 1] - prefix[j];
                if(subSum % 10 == x)
                {
                    int firstDig;
                    while(subSum)
                    {
                        firstDig = subSum % 10;
                        subSum /= 10;
                    }
                    if(firstDig == x)
                        result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 100, 1};
    int givenX = 1;
    int expectedAnswer = 4;
    assert(solution.countValidSubarrays(givenNums, givenX) == expectedAnswer);

    givenNums = {1};
    givenX = 2;
    expectedAnswer = 0;
    assert(solution.countValidSubarrays(givenNums, givenX) == expectedAnswer);

    return 0;
}

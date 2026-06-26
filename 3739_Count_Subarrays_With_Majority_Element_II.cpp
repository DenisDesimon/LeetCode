//#3739 Count Subarrays With Majority Element II - https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> countDiff(2 * n + 1);
        countDiff[n] = 1;
        int count = n;
        long long result = 0, preSumDif = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
            {
                preSumDif += countDiff[count];
                count++;
                countDiff[count]++;
            }else
            {
                count--;
                preSumDif -= countDiff[count];
                countDiff[count]++;
            }
            result += preSumDif;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 2, 3};
    int givenTarget = 2;
    int expectedAnswer = 5;
    assert(solution.countMajoritySubarrays(givenNums, givenTarget) == expectedAnswer);

    givenNums = {1, 1, 1, 1};
    givenTarget = 1;
    expectedAnswer = 10;
    assert(solution.countMajoritySubarrays(givenNums, givenTarget) == expectedAnswer);

    return 0;
}

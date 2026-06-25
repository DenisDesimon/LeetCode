//#3737 Count Subarrays With Majority Element I - https://leetcode.com/problems/count-subarrays-with-majority-element-i/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int countTarget = 0;
            for(int j = i; j < n; j++)
            {
                if(nums[j] == target)
                    countTarget++;
                if(countTarget > (j - i + 1) / 2)
                    result++;
            }
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

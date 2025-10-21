//#3346 Maximum Frequency of an Element After Performing Operations I - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> numsCount;
        for(auto &num : nums)
            numsCount[num]++;
        sort(nums.begin(), nums.end());
        int result = 1;
        for(int num = nums.front(); num <= nums.back(); num++)
        {
            int left = lower_bound(nums.begin(), nums.end(), num - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), num + k) - nums.begin();
            int repeats = numsCount.count(num) ? numsCount[num] : 0;
            result = max(result, min(numOperations, right - left - repeats) + repeats);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {88, 53};
    int givenK = 27;
    int givenNumOperations = 2;
    int expectedAnswer = 2;
    assert(solution.maxFrequency(givenNums, givenK, givenNumOperations) == expectedAnswer);

    givenNums = {5, 11, 20, 20};
    givenK = 5;
    givenNumOperations = 1;
    expectedAnswer = 2;
    assert(solution.maxFrequency(givenNums, givenK, givenNumOperations) == expectedAnswer);

    return 0;
}

//#3347 Maximum Frequency of an Element - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> countNums;
        unordered_set<int> numsTargets;
        int prevIdx = 0;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] != nums[prevIdx])
            {
                countNums[nums[prevIdx]] = i - prevIdx;
                numsTargets.insert(nums[prevIdx]);
                if(nums[prevIdx] + k < nums.back())
                    numsTargets.insert(nums[prevIdx] + k);
                if(nums[prevIdx] - k > nums.front())
                    numsTargets.insert(nums[prevIdx] - k);
                prevIdx = i;
            }
        }
        countNums[nums[prevIdx]] = nums.size() - prevIdx;
        numsTargets.insert(nums[prevIdx]);
        numsTargets.insert(nums[prevIdx] - k);
        int result = 1;
        for(auto &num : numsTargets)
        {
            int left = lower_bound(nums.begin(), nums.end(), num - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), num + k) - nums.begin();
            int repeated = countNums.count(num) ? countNums[num] : 0;
            result = max(result, min(right - left - repeated, numOperations) + repeated);
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

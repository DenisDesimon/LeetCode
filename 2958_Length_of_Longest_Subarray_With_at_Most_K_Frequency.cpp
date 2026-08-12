//#2958 Length of Longest Subarray With at Most K Frequency - https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> freq;
        for(; right < n; right++)
        {
            freq[nums[right]]++;
            while(freq[nums[right]] > k)
                freq[nums[left++]]--;
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 1, 2, 3, 1, 2};
    int givenK = 2;
    int expectedAnswer = 6;
    assert(solution.maxSubarrayLength(givenNums, givenK) == expectedAnswer);

    givenNums = {5, 5, 5, 5, 5, 5, 5};
    givenK = 4;
    expectedAnswer = 4;
    assert(solution.maxSubarrayLength(givenNums, givenK) == expectedAnswer);


    return 0;
}

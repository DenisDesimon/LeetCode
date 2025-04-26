//#2444 Count Subarrays With Fixed Bounds - https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int lastMinIdx = -1;
        int lastMaxIdx = -1;
        int lastOutidx = -1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] > maxK || nums[i] < minK)
                lastOutidx = i;
            if(nums[i] == minK)
                lastMinIdx = i;
            if(nums[i] == maxK)
                lastMaxIdx = i;
            result += max(0, min(lastMaxIdx, lastMinIdx) - lastOutidx);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 5, 2, 7, 5};
    int given_minK = 1;
    int given_maxK = 5;
    long long expected_answer = 2;
    assert(solution.countSubarrays(given_nums, given_minK, given_maxK) == expected_answer);

    given_nums = {1, 1, 1, 1};
    given_minK = 1;
    given_maxK = 1;
    expected_answer = 10;
    assert(solution.countSubarrays(given_nums, given_minK, given_maxK) == expected_answer);

    return 0;
}

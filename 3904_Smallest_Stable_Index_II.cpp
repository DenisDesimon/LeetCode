//#3904 Smallest Stable Index II - https://leetcode.com/problems/smallest-stable-index-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix.back() = nums.back();
        for(int i = n - 2; i >= 0; i--)
            suffix[i] = min(suffix[i + 1], nums[i]);
        int prefix = nums.front();
        for(int i = 0; i < n; i++)
        {
            prefix = max(prefix, nums[i]);
            if(prefix - suffix[i] <= k)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 0, 1, 4};
    int givenK = 3;
    int expectedAnswer = 3;
    assert(solution.firstStableIndex(givenNums, givenK) == expectedAnswer);

    givenNums = {3, 2, 1};
    givenK = 1;
    expectedAnswer = -1;
    assert(solution.firstStableIndex(givenNums, givenK) == expectedAnswer);


    return 0;
}

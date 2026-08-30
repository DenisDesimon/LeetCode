//#2091 Removing Minimum and Maximum From Array - https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0, maxIdx = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
            if(nums[i] < nums[minIdx])
                minIdx = i;
        }
        return min({max(minIdx, maxIdx) + 1, n - min(minIdx, maxIdx), min(minIdx, maxIdx) + n - max(minIdx, maxIdx) + 1});
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 10, 7, 5, 4, 1, 8, 6};
    int expectedAnswer = 5;
    assert(solution.minimumDeletions(givenNums) == expectedAnswer);

    givenNums = {0, -4, 19, 1, 8, -2, -3, 5};
    expectedAnswer = 3;
    assert(solution.minimumDeletions(givenNums) == expectedAnswer);

    return 0;
}

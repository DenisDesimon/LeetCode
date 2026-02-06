//#3634 Minimum Removals to Balance Array - https://leetcode.com/problems/minimum-removals-to-balance-array/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, result = 1;
        for(int right = 1; right < (int)nums.size(); right++)
        {
            while((long long)nums[left] * k < (long long)nums[right])
                left++;
            result = max(result, right - left + 1);
        }
        return nums.size() - result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 1, 5};
    int givenK = 2;
    int expectedAnswer = 1;
    assert(solution.minRemoval(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 6, 2, 9};
    givenK = 3;
    expectedAnswer = 2;
    assert(solution.minRemoval(givenNums, givenK) == expectedAnswer);


    return 0;
}

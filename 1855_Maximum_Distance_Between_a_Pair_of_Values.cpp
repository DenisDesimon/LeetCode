//#1855 Maximum Distance Between a Pair of Values - https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
       int left = 0, right = 1;
       while(left < (int)nums1.size() && right < (int)nums2.size())
       {
           if(nums1[left] > nums2[right])
               left++;
           right++;
       }
       return right - left - 1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums1 = {55, 30, 5, 4, 2};
    vector<int> givenNums2 = {100, 20, 10, 10, 5};
    int expectedAnswer = 2;
    assert(solution.maxDistance(givenNums1, givenNums2) == expectedAnswer);

    givenNums1 = {5, 4};
    givenNums2 = {3, 2};
    expectedAnswer = 0;
    assert(solution.maxDistance(givenNums1, givenNums2) == expectedAnswer);

    return 0;
}

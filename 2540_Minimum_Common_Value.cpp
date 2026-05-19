//#2540 Minimum Common Value - https://leetcode.com/problems/minimum-common-value/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0, j = 0; i < (int)nums1.size() && j < (int)nums2.size(); )
        {
            if(nums1[i] == nums2[j])
            {
                return nums1[i];
            }else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums1  = {1, 2, 3};
    vector<int> givenNums2  = {2, 4};
    int expectedAnswer = 2;
    assert(solution.getCommon(givenNums1, givenNums2) == expectedAnswer);

    givenNums1  = {1, 2, 3, 6};
    givenNums2  = {2, 3, 4, 5};
    expectedAnswer = 2;
    assert(solution.getCommon(givenNums1, givenNums2) == expectedAnswer);

    return 0;
}

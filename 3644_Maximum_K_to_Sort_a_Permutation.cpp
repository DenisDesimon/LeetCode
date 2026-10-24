//#3644 Maximum K to Sort a Permutation - https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int result = INT_MAX;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] != i)
                result &= nums[i];
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {0, 3, 2, 1};
    int expectedAnswer = 1;
    assert(solution.sortPermutation(givenNums) == expectedAnswer);

    givenNums = {0, 1, 3, 2};
    expectedAnswer = 2;
    assert(solution.sortPermutation(givenNums) == expectedAnswer);

    return 0;
}

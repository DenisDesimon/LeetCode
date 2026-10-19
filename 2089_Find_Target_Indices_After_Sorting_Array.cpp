//#2089 Find Target Indices After Sorting Array - https://leetcode.com/problems/find-target-indices-after-sorting-array/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count[101] = {0};
        for(auto &num : nums)
            count[num]++;
        vector<int> result;
        int idx = 0;
        for(int i = 0; i < 101; i++)
        {
            while(i == target && count[i])
            {
                result.push_back(idx);
                count[i]--;
                idx++;
            }
            idx += count[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 5, 2, 3};
    int givenTarget = 2;
    vector<int> expectedAnswer = {1, 2};
    assert(solution.targetIndices(givenNums, givenTarget) == expectedAnswer);

    givenNums  = {1, 2, 5, 2, 3};
    givenTarget = 3;
    expectedAnswer = {3};
    assert(solution.targetIndices(givenNums, givenTarget) == expectedAnswer);

    return 0;
}

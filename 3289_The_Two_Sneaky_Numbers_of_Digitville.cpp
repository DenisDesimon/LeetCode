//#3289 The Two Sneaky Numbers of Digitville - https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> unique(nums.size());
        vector<int> result;
        for(auto &num : nums)
        {
            if(unique[num])
                result.push_back(num);
            unique[num] = true;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 2, 1};
    vector<int> expectedAnswer = {2, 1};
    assert(solution.getSneakyNumbers(givenNums) == expectedAnswer);

    givenNums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    expectedAnswer = {4, 5};
    assert(solution.getSneakyNumbers(givenNums) == expectedAnswer);

    return 0;
}

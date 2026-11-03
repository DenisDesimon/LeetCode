//#3736 Minimum Moves to Equal Array Elements III - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int result = 0;
        for(auto &num : nums)
            result += maxNum - num;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 1, 3};
    int expectedAnswer = 3;
    assert(solution.minMoves(givenNums) == expectedAnswer);

    givenNums = {4, 4, 5};
    expectedAnswer = 2;
    assert(solution.minMoves(givenNums) == expectedAnswer);


    return 0;
}

//#2567 Minimum Score by Changing Two Elements - https://leetcode.com/problems/minimum-score-by-changing-two-elements/
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums.back() - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums.front()});
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 4, 7, 8, 5};
    int expectedAnswer = 3;
    assert(solution.minimizeSum(givenNums) == expectedAnswer);

    givenNums = {1, 4, 3};
    expectedAnswer = 0;
    assert(solution.minimizeSum(givenNums) == expectedAnswer);

    return 0;
}

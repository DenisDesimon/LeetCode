//#2044 Count Number of Maximum Bitwise-OR Subsets - https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private: int cnt(vector<int> &nums, int index, int curSubSet, int &target){
        if(index == (int)nums.size())
            return curSubSet == target ? 1 : 0;
        if(curSubSet == target)
            return (1 << (nums.size() - index));
        int include = cnt(nums, index + 1, curSubSet | nums[index], target);
        int exclude = cnt(nums, index + 1, curSubSet, target);
        return include + exclude;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto &num : nums)
            target |= num;
        return cnt(nums, 0, 0, target);
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 2, 1, 5};
    int expectedAnswer = 6;
    assert(solution.countMaxOrSubsets(givenNums) == expectedAnswer);

    givenNums = {3, 1};
    expectedAnswer = 2;
    assert(solution.countMaxOrSubsets(givenNums) == expectedAnswer);

    return 0;
}

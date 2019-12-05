//#462 Minimum Moves to Equal Array Elements II - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        for(auto& num : nums)
        {
            result += abs(num - median);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    int expected_answer = 2;
    assert(solution.minMoves2(given_nums) == expected_answer);

    given_nums = {1, 2, 3, 4};
    expected_answer = 4;
    assert(solution.minMoves2(given_nums) == expected_answer);

    return 0;
}

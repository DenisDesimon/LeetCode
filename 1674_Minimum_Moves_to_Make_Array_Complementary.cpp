//#1674 Minimum Moves to Make Array Complementary - https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2);
        int n = nums.size();
        for(int i = 0; i < n / 2; i++)
        {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }
        int result = INT_MAX;
        int cur = 0;
        for(int i = 2; i < 2 * limit + 2; i++)
        {
            cur += diff[i];
            result = min(result, cur);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 4, 3};
    int givenLimit = 4;
    int expectedAnswer = 1;
    assert(solution.minMoves(givenNums, givenLimit) == expectedAnswer);

    givenNums = {1, 2, 1, 2};
    givenLimit = 2;
    expectedAnswer = 0;
    assert(solution.minMoves(givenNums, givenLimit) == expectedAnswer);

    return 0;
}

//#1984 Minimum Difference Between Highest and Lowest of K Scores - https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for(int i = 0; i + k - 1 < (int)nums.size(); i++)
        {
            result = min(result, nums[i + k - 1] - nums[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {9, 4, 1, 7};
    int givenK = 2;
    int expectedAnswer = 2;
    assert(solution.minimumDifference(givenNums, givenK) == expectedAnswer);

    givenNums = {87063, 61094, 44530, 21297, 95857, 93551, 9918};
    givenK = 6;
    expectedAnswer = 74560;
    assert(solution.minimumDifference(givenNums, givenK) == expectedAnswer);

    return 0;
}

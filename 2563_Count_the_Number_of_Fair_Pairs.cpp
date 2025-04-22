//#2563 Count the Number of Fair Pairs - https://leetcode.com/problems/count-the-number-of-fair-pairs/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            vector<int>::iterator left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            vector<int>::iterator right = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            result += 1LL * (right - left);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 1, 7, 4, 4, 5};
    int given_lower = 3;
    int given_upper = 6;
    int expected_answer = 6;
    assert(solution.countFairPairs(given_nums, given_lower, given_upper) == expected_answer);

    given_nums = {1, 7, 9, 2, 5};
    given_lower = 11;
    given_upper = 11;
    expected_answer = 1;
    assert(solution.countFairPairs(given_nums, given_lower, given_upper) == expected_answer);

    return 0;
}

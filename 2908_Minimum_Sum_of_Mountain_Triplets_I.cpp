//#2908 Minimum Sum of Mountain Triplets I - https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int result = INT_MAX;
        vector<int> min_from_right(nums.size(), nums.back());
        for(int i = (int)nums.size() - 2; i > 0; i--)
            min_from_right[i] = min(min_from_right[i + 1], nums[i + 1]);
        int min_left = nums[0];
        for(int i = 1; i < (int)nums.size() - 1; i++)
        {
            if(nums[i] < min_left)
                min_left = nums[i];
            else if(nums[i] > min_left && nums[i] > min_from_right[i])
                result = min(result, nums[i] + min_left + min_from_right[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {8, 6, 1, 5, 3};
    int expected_answer = 9;
    assert(solution.minimumSum(given_nums) == expected_answer);

    given_nums = {1, 2, 3, 2};
    expected_answer = 6;
    assert(solution.minimumSum(given_nums) == expected_answer);

    given_nums = {2, 2, 1};
    expected_answer = -1;
    assert(solution.minimumSum(given_nums) == expected_answer);


    return 0;
}


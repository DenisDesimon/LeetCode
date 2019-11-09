//#665 Non-decreasing Array - https://leetcode.com/problems/non-decreasing-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        auto decrease_iter = is_sorted_until(nums.begin(), nums.end());
        if(decrease_iter == nums.end())
            return true;
        if(decrease_iter + 1 == nums.end())
            *decrease_iter = *(decrease_iter - 1);
        else if(*(decrease_iter - 1) > *(decrease_iter + 1))
        {
            decrease_iter--;
            *decrease_iter = *(decrease_iter + 1);
        }
        else
            *decrease_iter = *(decrease_iter + 1);
        decrease_iter = is_sorted_until(nums.begin(), nums.end());
        return decrease_iter == nums.end();
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 4, 2, 3};
    bool expected_answer = false;
    assert(solution.checkPossibility(given_nums) == expected_answer);

    given_nums = {2, 3, 3, 2, 4};
    expected_answer = true;
    assert(solution.checkPossibility(given_nums) == expected_answer);

    return 0;
}

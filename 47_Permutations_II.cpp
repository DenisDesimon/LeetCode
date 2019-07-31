//#47 Permutations II - https://leetcode.com/problems/permutations-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while(true)
        {
            result.push_back(nums);
            auto break_point = is_sorted_until(nums.rbegin(), nums.rend());
            if(break_point == nums.rend())
                break;
            auto upper = upper_bound(nums.rbegin(), break_point, *break_point);
            iter_swap(upper, break_point);
            reverse(nums.rbegin(), break_point);
            break_point = is_sorted_until(nums.rbegin(), nums.rend());
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 2};
    vector<vector<int>> expected_answer = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    assert(solution.permuteUnique(given_nums) == expected_answer);

    return 0;
}

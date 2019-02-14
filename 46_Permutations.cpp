//#46 Permutations - https://leetcode.com/problems/permutations/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while(true){
         result.push_back(nums);
         auto break_point = is_sorted_until(nums.rbegin(), nums.rend());
         if(break_point == nums.rend())
             break;
         auto iter_upper_bound = upper_bound(nums.rbegin(), break_point, *break_point);
         iter_swap(break_point, iter_upper_bound);
         reverse(nums.rbegin(), break_point);
                }
        return result;
                                                    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    vector<vector<int>> expected_answer = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3 ,1}, {3, 1, 2}, {3, 2, 1}};
    assert(solution.permute(given_nums) == expected_answer);

return 0;
}

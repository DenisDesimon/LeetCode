//#31 Next Permutation - https://leetcode.com/problems/next-permutation/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     vector<int>::reverse_iterator break_point = is_sorted_until(nums.rbegin(), nums.rend());
     if(break_point == nums.rend()){
         reverse(nums.rbegin(), nums.rend());
         return;
                                   }
     vector<int>::reverse_iterator iter_upper_bound = upper_bound(nums.rbegin(), break_point, *break_point);
     iter_swap(break_point, iter_upper_bound);
     reverse(nums.rbegin(), break_point);
                                                     }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    vector<int> expected_answer = {1, 3, 2};
    solution.nextPermutation(given_nums);
    assert(given_nums == expected_answer);

    given_nums = {3, 2, 1};
    expected_answer = {1, 2, 3};
    solution.nextPermutation(given_nums);
    assert(given_nums == expected_answer);

    return 0;
}

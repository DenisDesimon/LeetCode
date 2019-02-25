//#189 Rotate Array - https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-1, -100, 3, 99};
    int given_k = 2;
    vector<int>  expected_answer = {3, 99, -1, -100};
    assert(solution.rotate(given_nums, given_k) == expected_answer);

    given_nums = {1, 2, 3, 4, 5, 6, 7};
    given_k = 3;
    expected_answer = {5, 6, 7, 1, 2, 3, 4};
    assert(solution.rotate(given_nums, given_k) == expected_answer);

    return 0;
}

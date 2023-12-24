//#2974 Minimum Number Game - https://leetcode.com/problems/minimum-number-game/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size(); i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 4, 2, 3};
    vector<int> expected_answer = {3, 2, 5, 4};
    assert(solution.numberGame(given_nums) == expected_answer);

    given_nums = {2, 5};
    expected_answer = {5, 2};
    assert(solution.numberGame(given_nums) == expected_answer);

    return 0;
}

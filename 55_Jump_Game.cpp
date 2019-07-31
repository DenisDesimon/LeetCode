//#55 Jump Game - https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int last_pos = nums.size() - 1;
       for(int i = nums.size() - 1; i >= 0; i--)
       {
           if(i + nums[i] >= last_pos)
               last_pos = i;
       }
       return last_pos == 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 3, 1, 1, 4};
    bool expected_answer = true;
    assert(solution.canJump(given_nums) == expected_answer);

    given_nums = {3, 2, 1, 0, 4};
    expected_answer = false;
    assert(solution.canJump(given_nums) == expected_answer);

    return 0;
}

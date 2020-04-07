//#283 Move Zeroes - https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       for(int cur = 0, idx_zero = 0; cur < (int)nums.size(); cur++)
       {
           if(nums[cur] != 0)
               swap(nums[idx_zero++], nums[cur]);
       }
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 1, 0, 3, 12};
    vector<int> expected_answer = {1, 3, 12, 0, 0};
    solution.moveZeroes(given_nums);
    assert(given_nums == expected_answer);

    given_nums = {0, 0, 0, 3, 12};
    expected_answer = {3, 12, 0, 0, 0};
    solution.moveZeroes(given_nums);
    assert(given_nums == expected_answer);

    return 0;
}

//#136 Single Number - https://leetcode.com/problems/single-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < (int)nums.size(); i++)
         result ^= nums[i];
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_num = {2, 2, 1};
    int expected_answer = 1;
    assert(solution.singleNumber(given_num) == expected_answer);

    given_num = {4, 1, 2, 1, 2};
    expected_answer = 4;
    assert(solution.singleNumber(given_num) == expected_answer);

    given_num = {10};
    expected_answer = 10;
    assert(solution.singleNumber(given_num) == expected_answer);

    return 0;
}
